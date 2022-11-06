import Control.Arrow

sort str
    | odd l = str
    | a < b = a ++ b
    | True  = b ++ a
    where l     = length str
          (a,b) = (sort *** sort) $ splitAt (l`quot`2) str

main = do
    a <- getLine
    b <- getLine
    putStrLn $
        if
            sort a == sort b
        then
            "YES"
        else
            "NO"