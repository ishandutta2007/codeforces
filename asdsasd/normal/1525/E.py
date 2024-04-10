import sys
input = sys.stdin.readline
MOD = 998244353

def main():
    n, m = map(int, input().split())
    dlst = [list(map(int, input().split())) for _ in range(n)]
    ans = 0
    fact = 1
    for i in range(2, n + 1):
        fact *= i
        fact %= MOD
        
    for i in range(m):
        lst = [dlst[j][i] for j in range(n)]
        lst.sort(reverse = True)
        lst += [0]
        ret = 1
        s = 0
        pos = 0
        for j in range(n, 0, -1):
            while lst[pos] > j:
                s += 1
                pos += 1
            ret *= s
            s -= 1
        ans += fact - ret
        ans %= MOD
    print(ans * pow(fact, MOD - 2, MOD) % MOD)
        
    
    
for _ in range(1):
    main()