main = interact $ unlines . map (show . f . read) . tail . lines

f :: Integer -> Integer
f a = log2 (e+f) x + 4*5^(e+f-1)
        where r = mod (-a * 10^f) (2^(e+f))
              c = a*10^f+r
              c' = c + if mod c 5 == 0 then 2^(e+f) else 0
              x = mod c' (5^(e+f))
              e = head $ filter ((>a).(10^)) [0..]
              f = head $ filter (\i-> 2^(e+i+1)<10^i) [0..]

powMod :: Integer -> Integer -> Integer -> Integer       
powMod a 0 m = 1
powMod a e m = mod (powMod (mod (a^2) m) (div e 2) m * (if even e then 1 else a)) m

log2 :: Int -> Integer -> Integer
log2 i x
        | i == 0    = 0
        | otherwise = head $ filter (\e-> powMod 2 e (5^i) == x) [a,a+phi..]
        where a = log2 (i-1) (mod x (5^(i-1)))
              phi = if i == 1 then 1 else 4*5^(i-2)