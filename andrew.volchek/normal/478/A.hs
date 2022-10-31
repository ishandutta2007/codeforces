module Main where

import Data.Maybe
import Data.List


solve :: [Int] -> Maybe Int
solve xs = if x `mod` y == 0 && x > 0 then Just(x `div` y) else Nothing
	where
		x = sum xs
		y = length xs

readList' :: String -> [Int]
readList' xs = map read $ words xs

main :: IO ()
main = do
	line <- getLine
	case solve (readList' line) of
		Just x -> putStrLn $ show x
		Nothing -> putStrLn "-1"