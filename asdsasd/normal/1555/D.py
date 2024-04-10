import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    S = input().strip()
    cand = ["abc", "acb", "bac", "bca", "cab", "cba"]
    cum = [[0] * (n + 1) for _ in range(6)]
    for j, s in enumerate(S, 1):
        j3 = j % 3
        for i, T in enumerate(cand):
            cum[i][j] = cum[i][j - 1]
            if T[j3] != s:
                cum[i][j] += 1
    for _ in range(m):
        l, r = map(int, input().split())
        l -= 1
        ans = 10 ** 10
        for i in range(6):
            ans = min(ans, cum[i][r] - cum[i][l])
        print(ans)
    
for _ in range(1):
    main()