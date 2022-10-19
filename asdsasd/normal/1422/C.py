import sys
input = sys.stdin.readline

MOD = 10 ** 9 + 7
N = 10 ** 5 + 100

fact = [0 for _ in range(N)]
invfact = [0 for _ in range(N)]
fact[0] = 1
for i in range(1, N):
    fact[i] = fact[i - 1] * i % MOD

invfact[N - 1] = pow(fact[N - 1], MOD - 2, MOD)

for i in range(N - 2, -1, -1):
    invfact[i] = invfact[i + 1] * (i + 1) % MOD
def nCk(n, k):
    if k < 0 or n < k:
        return 0
    else:
        return fact[n] * invfact[k] * invfact[n - k] % MOD

def main():
    n = input().strip()
    ans = 0
    l = len(n)
    plus = 0
    plus2 = 1
    plus3 = 1
    for i, str_num in enumerate(n[::-1]):
        num = int(str_num)
        j = l - i - 1
        ans += nCk(j + 1, 2) * pow(10, i, MOD) * num
        ans %= MOD
        ans += num * plus
        ans %= MOD
        plus += plus2 * plus3
        plus2 *= 10
        plus3 += 1
        plus %= MOD
        plus2 %= MOD
        plus3 %= MOD

    print(ans)
        
        
main()