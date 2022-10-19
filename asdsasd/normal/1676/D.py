import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    A = [list(map(int, input().split())) for _ in range(n)]
    plus = {}
    minus = {}
    for i in range(n):
        for j in range(m):
            plus[i + j] = plus.get(i + j, 0) + A[i][j]
            minus[i - j] = minus.get(i - j, 0) + A[i][j]
    ans = 0
    for i in range(n):
        for j in range(m):
            ans = max(ans, plus[i + j] + minus[i - j] - A[i][j])
    print(ans)


for _ in range(int(input())):
    main()