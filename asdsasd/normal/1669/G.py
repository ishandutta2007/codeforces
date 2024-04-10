import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    S = [list(input().strip()) for _ in range(n)] + [["o"] * m]
    ans = [["."] * m for _ in range(n)]
    for j in range(m):
        cnt = 0
        for i in range(n + 1):
            if S[i][j] == "*":
                cnt += 1
            elif S[i][j] == "o":
                for k in range(cnt):
                    ans[i - 1 - k][j] = "*"
                cnt = 0
                if i != n:
                    ans[i][j] = "o"
    
    for row in ans:
        print(*row, sep="")
    
    
for _ in range(int(input())):
    main()