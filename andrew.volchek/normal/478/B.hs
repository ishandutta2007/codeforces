module Main where

import Data.Char


readInt :: IO Int
readInt =
	do 
		ch <- getChar
		if isDigit ch
		then readInt' $ ord(ch) - ord('0')
		else readInt
		
readInt' :: Int -> IO Int
readInt' acc = 
	do
		ch <- getChar
		if isDigit ch
		then readInt' (acc * 10 + ord ch - ord '0')
		else return acc

---------------------------------------------------------------------------------------------

solveMin :: Integer -> Integer -> Integer
solveMin n m = x * (x + 1) `div` 2 * y + x * (x - 1) `div` 2 * (m - y)
	where
		x = n `div` m
		y = n `mod` m

solveMax :: Integer -> Integer -> Integer
solveMax n m = 
	let x = n - m + 1
	in x * (x - 1) `div` 2

main :: IO ()
main =
	do
		n <- fmap toInteger $ readInt 
		m <- fmap toInteger $ readInt
		putStrLn $ (show $ solveMin n m) ++ " " ++ (show $ solveMax n m)