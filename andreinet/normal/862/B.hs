import qualified Data.Set as Set
import System.IO

type Edge = (Int, Int)
readInt = read :: String -> Int

split :: Set.Set Edge -> Int -> Int -> (Int, Int, Set.Set Edge)
split edges node color =
    let
        col1 = if color == 0 then 1 else 0
        col2 = if color == 1 then 1 else 0
        firstEdge = Set.lookupGE (node, -1) edges
        in
        case firstEdge of
            Nothing -> (col1, col2, edges)
            Just (x, y) ->
                if x /= node then (col1, col2, edges)
                else let
                        nEdges = ((Set.delete (x, y)).(Set.delete (y, x))) edges
                        (col1', col2', edges') = split nEdges y (1 - color)
                        (col1'', col2'', edges'') = split edges' node color
                        in
                        (col1' + col1'', col2' + col2'', edges'')



main = do
    hSetBuffering stdin $ BlockBuffering (Just (2 ^ 15))
    l1 <- getLine
    l2 <- getContents
    let
        n = read l1 :: Int
        edges' = map ((\[x, y] -> (readInt x, readInt y)).words) $ lines l2
        edges'' = edges' ++ (map (\(x, y) -> (y, x)) $ reverse edges')
        edges = Set.fromList edges''
        (v1, v2, _) = split edges 1 0
        in
        print $ (toInteger v1) * (toInteger v2) - toInteger (n - 1)