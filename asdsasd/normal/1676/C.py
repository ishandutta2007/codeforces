import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    S = [input().strip() for _ in range(n)]
    ans = 1 << 30
    for i in range(n):
        for j in range(i + 1, n):
            tot = 0
            for k in range(m):
                p1 = ord(S[i][k]) - 97
                p2 = ord(S[j][k]) - 97
                d = p1 - p2
                tot += abs(p1 - p2)
            ans = min(ans, tot)
    print(ans)

for _ in range(int(input())):
    main()