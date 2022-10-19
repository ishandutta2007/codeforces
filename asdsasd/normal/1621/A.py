import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    if (n + 1) // 2 < k:
        print(-1)
        return
    ans = [["."] * n for _ in range(n)]
    for i in range(0, 2 * k, 2):
        ans[i][i] = "R"
    for row in ans:
        print(*row, sep="")
    
for _ in range(int(input())):
    main()