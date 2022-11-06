import Text.Printf

main = do
    [t,w,b] <- fmap (map read . words) getLine
    let mgm = lcm w b
        mn  = min w b
        ans = t`quot`mgm * mn + min mn ((1::Integer) + t `rem` mgm) - 1
        sgd = gcd t ans
    printf "%d/%d\n" (ans`quot`sgd) (t`quot`sgd)