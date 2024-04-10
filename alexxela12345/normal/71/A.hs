shorten :: String -> String
shorten s
  | length s <= 10 = s
  | otherwise = [head s] ++ show (length s - 2) ++ [last s]

solve :: String -> String
solve input = unlines $ map shorten $ tail $ lines input

main :: IO ()
main = interact solve