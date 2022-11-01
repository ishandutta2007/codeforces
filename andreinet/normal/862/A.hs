import qualified Data.Set as Set

main = do
    l1 <- getLine
    l2 <- getLine

    let
        [n, m] = map (read :: String -> Int) $ words l1
        numbers = map (read :: String -> Int) $ words l2
        in
        print $ (m - (length $ filter (<m) numbers)) + (if m `elem` numbers then 1 else 0)