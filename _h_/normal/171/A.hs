main = do
	[a,b] <- fmap words getLine
	print $ read a + read (reverse b)