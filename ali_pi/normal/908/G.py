n = map(int,raw_input())
mod = 10 ** 9 + 7
l = len(n)
f = [0] * (l + 1)
for i in xrange(l):
    f[i+1] = (f[i] * 10 + 1) % mod
t = [1] * (l + 1)
for i in xrange(l):
    t[i+1] = t[i] * 10 % mod
ans = 0
for i in xrange(1, 10):
    dp = [0] * (l + 1)
    for j in xrange(l):
        dp[j+1] = (dp[j] * i + (10 - i) * (dp[j] * 10 + t[j])) % mod
    c = 0
    for j, k in enumerate(n):
        z = min(i, k)
        o = k - z
        ans += o * (dp[l-1-j] * t[c+1] + f[c+1] * t[l-1-j]) % mod
        ans += z * (dp[l-1-j] * t[c] + f[c] * t[l-1-j]) % mod
        ans %= mod
        c += k >= i
    ans += f[c]
    if ans >= mod:
        ans -= mod
print(ans)