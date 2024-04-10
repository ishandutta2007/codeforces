module Main where

import Control.Applicative
import Data.List
import Control.Monad
import Control.Arrow
import Data.Function
import Data.Array

main' a b = f a 0
    where
        f 0 _ = []
        f a c
            | c == b = (g 0) : f (a-1) 1
            | otherwise = (g c) : f (a-1) (c+1)
        r = listArray (0,b-1)$ (sortBy(compare`on`snd)$map(\i->(i,abs$(intToFlt(b+1)/2.0)-intToFlt i))[1..b])
        g c = fst$ r!c


intToFlt = fromInteger.toInteger

main = putStrLn=<<unlines.map show.(\[a,b]->main' a b).map read.words<$>getLine