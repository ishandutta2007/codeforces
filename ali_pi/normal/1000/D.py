mod = 998244353
n = input()
a = list(map(int, raw_input().split()))
c = [[1]*n for _ in range(n)]
for i in range(n):
    for j in range(1, i//2 + 1):
        c[i][i-j] = c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod
d = [0] * n + [1]
for i in range(n-1,-1,-1):
    if a[i] <= 0:
        continue
    for j in range(i+a[i]+1,n+1):
        d[i] += (d[j] * c[j-i-1][a[i]])
    d[i] %= mod
print((sum(d)-1)%mod)