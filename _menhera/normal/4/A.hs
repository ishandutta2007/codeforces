div4 :: Int -> [Char]
div4 x
	| x < 4 = "NO"
	| x `mod` 2 == 0 = "YES"
	| otherwise = "NO"
	
main = do
    a <- getLine ;
	putStr $ div4 (read a)