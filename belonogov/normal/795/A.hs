{-# LANGUAGE ScopedTypeVariables #-} {-# LANGUAGE BangPatterns #-}

import Control.Applicative
import Control.Monad
import Control.Arrow
import Data.List
import Data.Maybe
import Data.Char
import qualified Data.ByteString.Char8 as B
import Text.Printf

readInteger = ( readLn :: IO Integer )
readIntegers = map ( read :: String -> Integer ) . words <$> getLine

getList = map ( fst . fromJust . B.readInteger ) . B.words <$> B.getLine

which a b f = if f then a else b
mp [ a, b ] = ( a, b )


countPar :: String -> Integer
countPar [] = 0
countPar ('0':xs) = countPar xs
countPar ('1':xs) = (countPar xs) + 1

countCh :: String -> Integer
countCh [] = 0
countCh ('1':xs) = countCh xs
countCh ('0':xs) = (countCh xs) + 1


calc n c1 c2 cg = (cg - add) * (c1 + (sz - 1) * (sz - 1) * c2) + add * (c1 + (sz + 0) * (sz + 0) * c2)
        where 
            sz = n `div` cg  
            add = n `mod` cg


solve :: Integer -> Integer -> Integer -> Integer -> Integer
solve 0 n c1 c2 = 1000000000000000000 
solve cg n c1 c2 = min (solve (cg - 1) n c1 c2) (calc n c1 c2 cg)

main = do
    [ n, c1, c2 ] <- readIntegers
    s <- getLine 
    let par = countPar s
    {-prInteger par-}
    print (solve par n c1 c2)
    {-prInteger answer-}

    {-as <- getList-}
    {-prInteger $ ( `div` 2 ) $ succ $ sum $ map ( \m -> ( m + k - 1 ) `div` k ) as-}


{-import Data.List (sort)-}
{-main = do-}
  {-(n:k:as) <- fmap (map read . words) getContents-}
  {-let ks = (sort as) !! (n-k)-}
  {-prInteger . length . filter (> 0) . filter (>= ks) $ as-}



{-import Data.List (sort)-}
{-main = do-}
  {-(n:c1:c2) <- fmap (map read . words) getContents-}
  {-{-s <- getLine-}-}
  {-prInteger "ADF"-}
  {-{-prInteger s-}-}
  {-{-let ks = (sort as) !! (n-k)-}-}
  {-{-prInteger . length . filter (> 0) . filter (>= ks) $ as-}-}