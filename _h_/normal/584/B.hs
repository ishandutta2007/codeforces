main = interact $(++"\n") . show . (\n-> (modexp 27 n - modexp 7 n) `mod` md) . read

md :: Integer
md = 10^9+7
modexp b 0 = 1
modexp b e = modexp (b*b`rem`md) q * (if r == 0 then 1 else b) `rem` md
	where (q,r) = quotRem e 2