def binpow(x, t, mod):
    if t == 0:
        return 1
    if t % 2 == 0:
        return binpow(x * x % mod, t//2, mod)
    return binpow(x, t-1, mod) * x % mod

def calc(a, f, rv, n):
    mod = 10 ** 9 + 7
    s = 0
    ans = 1
    for i in range(len(a)-1, -1, -1):
        cur = n//a[i]
        if i > 0:
            cur -= n//a[i-1]
        t = cur-1
        s += t
        ans = ans * cur * f[s] * rv[s-t] % mod
        #print(a[i], cur, s, f[s], rv[s-t])
        s += 1
    return ans
n = int(input())
x = n
c = 0
while x > 1:
    x //= 2
    c+=1
f = [1] * 1000100
mod = 10**9 + 7
for i in range(1, len(f)):
    f[i] = f[i-1] * i % mod
rv = [1] * 1000100
rv[-1] = binpow(f[-1], mod-2, mod)
for i in range(len(f)-2, 0, -1):
    rv[i] = rv[i+1] * (i+1) % mod
a = []
for i in range(c, -1, -1):
    a.append(2**i)
ans=calc(a, f, rv, n)
if (2**(c-1)) * 3 <= n:
    c -= 1
    a = []
    while c >= 0:
        a.append((2**c) * 3)
        b = a.copy()
        for i in range(c, -1, -1):
            b.append(2**i)
        ans = (ans + calc(b, f, rv, n)) % mod
        c -= 1
print(ans)