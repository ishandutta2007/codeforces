solve :: String -> String
solve s =
  show $
  length $ filter (\x -> (length . filter (== '1')) x >= 2) $ tail $ lines s

main :: IO ()
main = interact solve