module Main where

import Control.Applicative
import Data.List
import Control.Monad
import Control.Arrow
import Data.Function
import Data.Array

f :: Integer -> Integer -> Integer
f l r = g r - g (l-1)

g x
    | x < 10 = x
    | True = g (10^(keta x-1)-1) + k x
keta x
    | x < 10 = 1
    | True = succ$ keta (x`div`10)
k x
    | x < 10 = x
    | True = (x`div`10)-(10^(keta x-2)) + l x
l x
    | x < 10 = 0
    | (x`div`(10^(keta x-1))) <= x `mod` 10 = 1
    | True = 0
{-
    5
    1???1
    ` 9???9
    
-}

main = do
    (l, r) <- (\[x,y]->(x,y)). map read. words <$> getLine
    print$ f l r