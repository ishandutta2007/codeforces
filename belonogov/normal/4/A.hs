main = do
    str <- getLine
    let x = read str :: Integer
    putStrLn $ if (x > 2 && even x) then "YES" else "NO"