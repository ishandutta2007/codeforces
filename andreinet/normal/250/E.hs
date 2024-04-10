import System.IO
import Data.List
import Data.Function(on)

data Dir = DLeft | DRight deriving (Eq)

solve :: [String] -> Int -> Dir -> Maybe Integer
solve (l1:[]) pos _ = Just 0
solve (l1:l2:xs) pos dir
    | (l2!!pos == '.') =
        let v = solve(l2:xs) pos dir
        in case v of Nothing -> Nothing
                     Just x -> Just (1 + x)
    | otherwise = let
                    n = (length l1) - 1
                    (leftPart, _:rightPart) = splitAt pos l2
                    leftPos' = findIndices (=='.') leftPart
                    rightPos' = findIndex (=='.') rightPart
                    leftPos = if (not $ null leftPos') then (last leftPos') else 0
                    rightPos = case rightPos' of
                                    Nothing -> n
                                    Just x -> pos + 1 + x
                    (upLeftPart, _:upRightPart) = splitAt pos l1
                    blockLeft = last $ findIndices (=='#') upLeftPart
                    blockRight = pos + 1 + (head $ findIndices (=='#') upRightPart)
                    leftIndexed = zip upLeftPart [0..]
                    rightIndexed = zipWith (\x y -> (x, y + pos + 1)) upRightPart [0..]
                    in if (blockLeft >= leftPos && blockRight <= rightPos) then Nothing
                       else if blockRight > rightPos && blockLeft >= leftPos then
                            let
                                takeRight = (:) ('.', rightPos + 1) $ filter ((=='+').fst) $ takeWhile (\(x, y) -> y <= rightPos) rightIndexed
                                stepsRight = length takeRight
                                stepsLeft = stepsRight - (if dir == DRight then 1 else 0)
                                takeLeft' = take stepsLeft $ filter ((=='+').fst) $ takeWhile (\(x, y) -> x /= '#') $ reverse leftIndexed
                                takeLeft = (replicate (max 0 $ stepsLeft - length takeLeft') ('#', blockLeft)) ++ takeLeft'
                                nextAnswer = solve (l2:xs) rightPos DRight
                                -- nextAnswer = Just 0
                                in
                                -- Just (snd $ head takeRight)
                                -- Just (2 * foldl (\s (x, y) -> s + y - 1) 0 takeRight - 2 * (length takeRight) * pos)
                                -- Just ((computeTake takeLeft takeRight pos))
                                -- nextAnswer
                                case nextAnswer of
                                    Nothing -> Nothing
                                    (Just x) -> Just (x + (toInteger $ (computeTake takeLeft takeRight pos) - abs (pos - rightPos) + 1))
                        else if (blockLeft < leftPos && blockRight <= rightPos) then
                            let
                                takeLeft = (:) ('.', leftPos - 1) $ filter ((=='+').fst) $ takeWhile (\(x, y) -> y >= leftPos) $ reverse leftIndexed
                                stepsLeft = length takeLeft
                                stepsRight = stepsLeft - (if dir == DLeft then 1 else 0)
                                takeRight' = take stepsRight $ filter ((=='+').fst) $ takeWhile (\(x, y) -> x /= '#') rightIndexed
                                takeRight = (++) takeRight' $ replicate (max 0 $ stepsRight - length takeRight') ('#', blockRight)
                                nextAnswer = solve (l2:xs) leftPos DLeft
                                in
                                -- Just (length takeRight)
                                case nextAnswer of
                                    Nothing -> Nothing
                                    (Just x) -> Just (x + (toInteger $ (computeTake takeLeft takeRight pos) - abs (pos - leftPos) + 1))
                        else
                            let
                                takeLeft' = filter ((=='+').fst) $ takeWhile (\(x, y) -> y >= leftPos) $ reverse leftIndexed
                                takeRight' = filter ((=='+').fst) $ takeWhile (\(x, y) -> y <= rightPos) rightIndexed
                                minLength = (min `on` length) takeLeft' takeRight'
                                lengthLeft = length takeLeft'
                                lengthRight = length takeRight'
                                (nextPos, nextDir) = if lengthLeft == lengthRight then
                                                        if dir == DLeft then (leftPos, DLeft)
                                                        else (rightPos, DRight)
                                                     else if lengthLeft < lengthRight then (leftPos, DLeft)
                                                     else (rightPos, DRight)
                                stepsLeft = minLength + (if nextDir == DRight && dir == DLeft then 1 else 0)
                                stepsRight = minLength + (if nextDir == DLeft && dir == DRight then 1 else 0)
                                takeLeft = (if nextDir == DLeft then [('.', leftPos - 1)] else []) ++ (take stepsLeft takeLeft')
                                takeRight = (if nextDir == DRight then [('.', rightPos + 1)] else []) ++ (take stepsRight takeRight')
                                nextAnswer = solve (l2:xs) nextPos nextDir
                                -- nextAnswer = 0
                                in
                                -- Just (if nextDir == DRight then 1 else 0)
                                -- Just (2 * (length takeLeft) * pos - 2 * foldl (\s (x, y) -> s + y + 1) 0 takeLeft)
                                -- Just ((computeTake takeLeft takeRight pos)- abs (pos - nextPos) + 1)
                                case nextAnswer of
                                    Nothing -> Nothing
                                    (Just x) -> Just (x + (toInteger $ (computeTake takeLeft takeRight pos) - abs (pos - nextPos) + 1))

    where
        computeTake takeLeft takeRight pos =
            let stepsLeft = length takeLeft; stepsRight = length takeRight in
                (2 * foldl (\s (x, y) -> s + y - 1) 0 takeRight -
                2 * foldl (\s (x, y) -> s + y + 1) 0 takeLeft +
                2 * (stepsLeft - stepsRight) * pos + stepsLeft + stepsRight - 1)

main = do
    firstLine <- getLine
    other <- getContents
    let
        [n, m] = map read $ lines firstLine :: [Int]
        matrix = map (('#':).(++"#")) $ takeWhile (not.null) $ lines other
        in
        -- print $ matrix
        putStrLn $ result $ solve matrix 1 DRight
            where result Nothing = "Never"
                  result (Just x) = show x