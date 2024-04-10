import sys
input = sys.stdin.readline
MOD = 10 ** 9 + 7

def main():
    n, k = map(int, input().split())
    if k == 0:
        print(1)
        return
    if n == 1:
        print(pow(2, k, MOD))
        return
    if n % 2 == 1:
        print(pow(pow(2, n - 1, MOD) + 1, k, MOD))
    else:
        ans = pow(pow(2, n - 1, MOD) - 1 , k, MOD)
        for i in range(k):
            ans += pow(pow(2, n - 1, MOD) - 1, i, MOD) * pow(pow(2, n, MOD), k - 1 - i, MOD)
            ans %= MOD
        print(ans)
            
    
for _ in range(int(input())):
    main()