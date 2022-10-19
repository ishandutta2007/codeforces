import sys
I=lambda:[*map(int,sys.stdin.readline().split())]
M=10**9+7

t, = I()
for _ in range(t):
    n, = I()
    b = I()
    dp = {0:1}
    s = 0
    K = 1
    for x in b:
        a = dp.get(s, 0)
        dp[s] = K
        K = (2*K-a)%M
        s += x
    print(K)