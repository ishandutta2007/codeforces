N, M = map(int, input().split())

fac = [1] + [0] * N
for i in range(1, N + 1):
    fac[i] = fac[i - 1] * i % M
fac_inv = [0] * N + [pow(fac[N], M - 2, M)]
for i in range(N, 0, -1):
    fac_inv[i - 1] = fac_inv[i] * i % M
pow2 = [1] + [0] * N
for i in range(N):
    pow2[i + 1] = pow2[i] * 2 % M

DP = [[0] * N for _ in range(N + 2)]
DP[0][0] = 1
for i in range(N):
    for j in range(N):
        DP[i][j] %= M
        if DP[i][j]:
            for k in range(i + 2, N + 2):
                DP[k][j + 1] += DP[i][j] * fac_inv[k - i - 1] % M * pow2[k - i - 2] % M
ans = 0
for j in range(N):
    DP[N + 1][j] %= M
    if DP[N + 1][j]:
        ans += DP[N + 1][j] * fac[N - j + 1] % M
print(ans % M)