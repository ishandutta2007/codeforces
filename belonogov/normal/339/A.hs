

g1 :: [Int] -> [Int]
g1 (a:s) = (a + 1):s

g2 :: [Int] -> [Int]
g2 (a:b:s) = (a):(b + 1):s

g3 :: [Int] -> [Int]
g3 (a:b:c:s) = (a):(b):(c + 1):s

solve :: String -> [Int]
solve "" = [0, 0, 0]
solve ('+':s) = solve s 
solve ('1':s) = g1 (solve s)
solve ('2':s) = g2 (solve s)
solve ('3':s) = g3 (solve s)

gen :: [Int] -> String
gen [0, 0, 0] = ""
gen [0, 0, a] = "+3" ++ (gen [0, 0, a - 1])
gen [0, a, b] = "+2" ++ (gen [0, a - 1, b])
gen [a, b, c] = "+1" ++ (gen [a - 1, b, c])

cuttt (ch:s) = s

main = do 
    s <- getLine
    let t = solve s
    let answer = gen t;
    let qq = "sdfsdf"
    --print qq
    --print 5
    putStrLn (cuttt answer)