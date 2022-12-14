from fractions import gcd

t, a, b = map(int, input().split())

if a > b:
    a, b = b, a

lcm = a * b // gcd(a, b)
cnt = t // lcm
lst = lcm * cnt

ans = cnt * a + a - 1 

if lst + a > t + 1:
    ans -= lst + a - t - 1

num = ans
den = t

g = gcd(num, den)
num //= g
den //= g

print(num, den, sep='/')