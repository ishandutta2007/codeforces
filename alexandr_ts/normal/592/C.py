from fractions import gcd
s = list(map(int, input().split()))
t = s[0]
a = s[1]
b = s[2]
nod = gcd(a, b)
nok = a * b // nod
ans = t // nok * min(a, b) + min(a, b) - 1
ans -= max(0, ((t // nok) * nok) + min(a, b) - 1 - t)
gc = gcd(ans, t)
ans //= gc
t //= gc
print(str(int(ans)) + '/' + str(int(t)))