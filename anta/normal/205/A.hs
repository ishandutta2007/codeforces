module Main where

import Control.Applicative
import Data.List
import Control.Monad
import Control.Arrow
import Data.Function
import Data.Array

main = do
    getLine
    xs <- map (read::String->Int). words <$> getLine
    let
        m = minimum xs
        f = filter ((m==). snd)$ zip [1..] xs
    if length f == 1 then print. fst. head$ f
        else putStrLn "Still Rozdil"