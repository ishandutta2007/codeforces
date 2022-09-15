-- String, Lowercase, Uppercase, Boolean
isAppearAll :: [Char] -> [Char] -> [Char] -> Bool

isAppearAll _ [] [] =
	True
isAppearAll s (l:ls) (u:us) =
	( (elem l s) || (elem u s) ) &&  isAppearAll s ls us

isPangram :: [Char] -> Bool
isPangram s = 
		isAppearAll s lc uc 	
	where
		lc = ['a'..'z']
		uc = ['A'..'Z']
main :: IO()
main = do
	getLine
	a <- getLine
	if isPangram a
		then putStrLn "YES"
		else putStrLn "NO"