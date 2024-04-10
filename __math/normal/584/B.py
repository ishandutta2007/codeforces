n = int(raw_input())
MOD = 10**9 + 7
ans = pow(3,3*n,MOD) - pow(7,n)
print ans % MOD