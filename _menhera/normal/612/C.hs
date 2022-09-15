import Data.Maybe
import Data.Bool
import Control.Monad

convL2R :: Char -> Char
convL2R '[' = ']'
convL2R '{' = '}'
convL2R '(' = ')'
convL2R '<' = '>'
convL2R _ = undefined

isrbr :: Char -> Bool
isrbr ']' = True
isrbr '}' = True
isrbr ')' = True
isrbr '>' = True
isrbr _ = False

solve' :: String -> [Char] -> Maybe Int
solve' (x:xs) y
 | and [isrbr x, y == []] = Nothing
 | isrbr x = liftM2 (+) (if x == head y then Just 0 else Just 1) (solve' xs (tail y) )
 | otherwise = solve' xs ([convL2R x] ++ y)
 
solve' _ [] = Just 0
solve' _ _ = Nothing



solve :: String -> Maybe Int
solve x = solve' x [] 

pImpossible :: Maybe Int -> String

pImpossible Nothing = "Impossible\n"
pImpossible a = show $ fromJust a


parse :: String -> String

parse = pImpossible . solve . unwords. words




main = interact parse