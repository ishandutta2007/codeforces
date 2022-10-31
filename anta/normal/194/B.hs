import Control.Applicative
import Data.List
--import Test.QuickCheck

main'fast :: Integer -> Integer
main'fast 1 = 3
main'fast n
    | n `mod` 2 == 0 = n * 4 + 1
    | n `mod` 4 == 1 = n * 2 + 1
    | otherwise = n + 1

--main'slow :: Integer -> Integer
main'slow n = (+2). genericLength. takeWhile (/=0). tail$ iterate f 0 where
    f x = (x + n + 1) `mod` (n*4)

--prop_main' x = x >= 1 ==> main'slow x == main'fast x

main = do
    getLine
    ss <- getLine
    putStrLn$ unlines. map (show. main'fast. read). words$ ss