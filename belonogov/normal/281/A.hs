
import Data.Char


f (ch:s) = (toUpper ch):s 

main = do 
    s <- getLine
    putStrLn (f s)