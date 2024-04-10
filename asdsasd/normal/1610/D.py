import sys
input = sys.stdin.readline
MOD = 10 ** 9 + 7

def main():
    n = int(input())
    A = list(map(int, input().split()))
    cnt = [0] * 40
    for a in A:
        c = 0
        while a % 2 == 0:
            a //= 2
            c += 1
        cnt[c] += 1
    tot = 0
    ans = pow(2, n, MOD) - pow(2, n - cnt[0], MOD)
    ans %= MOD
    tot = cnt[0]
    for i in range(1, 35):
        tot += cnt[i]
        if cnt[i] == 0:
            continue
        j = pow(2, cnt[i] - 1, MOD) - 1
        ans += j * pow(2, n - tot, MOD)
        ans %= MOD
    print(ans)
    
for _ in range(1):
    main()