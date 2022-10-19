import sys
input = sys.stdin.readline
MOD = 998244353

def main():
    n = int(input())
    A = list(map(int, input().split()))
    cnt = {}
    ans = 0
    for l in range(n - 1, -1, -1):
        cnt2 = {}
        a = A[l]
        for k, v in cnt.items():
            tmp = (a + k - 1) // k
            x = a // tmp
            cnt2[x] = cnt2.get(x, 0) + v
            ans += (tmp - 1) * (l + 1) * v
            ans %= MOD
        cnt = cnt2
        cnt[a] = cnt.get(a, 0) + 1
    
    print(ans)
    
    
for _ in range(int(input())):
    main()