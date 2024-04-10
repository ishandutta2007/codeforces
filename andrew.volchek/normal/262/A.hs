import Prelude

main = do 
	str <- getContents
	print $ solve str

solve :: String -> Int
solve str = length $ filter (<=k) $ ln 
	where
		(ns:ks:a) = words str
		n = read ns
		k =  read ks
		aa = take n a
		ln = map toLucky aa
		toLucky number = length $ filter (\chr -> (chr == '7') || (chr == '4')) $ number