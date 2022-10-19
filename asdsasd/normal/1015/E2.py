import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    S = [input().strip() for _ in range(n)]
    U = [[0] * m for _ in range(n)]
    for j in range(m):
        cnt = 0
        for i in range(n):
            U[i][j] = cnt
            if S[i][j] == "*":
                cnt += 1
            else:
                cnt = 0
                
    D = [[0] * m for _ in range(n)]
    for j in range(m):
        cnt = 0
        for i in range(n - 1, -1, -1):
            D[i][j] = cnt
            if S[i][j] == "*":
                cnt += 1
            else:
                cnt = 0
    
    L = [[0] * m for _ in range(n)]
    for i in range(n):
        cnt = 0
        for j in range(m):
            L[i][j] = cnt
            if S[i][j] == "*":
                cnt += 1
            else:
                cnt = 0
                
    R = [[0] * m for _ in range(n)]
    for i in range(n):
        cnt = 0
        for j in range(m - 1, -1, -1):
            R[i][j] = cnt
            if S[i][j] == "*":
                cnt += 1
            else:
                cnt = 0
    
    row = [[0] * (m + 1) for _ in range(n)]
    col = [[0] * m for _ in range(n + 1)]
    ans = []
    for i in range(n):
        for j in range(m):
            if S[i][j] == "*":
                x = min(U[i][j], D[i][j], L[i][j], R[i][j])
                if x != 0:
                    ans.append((i + 1, j + 1, x))
                    col[i - x][j] += 1
                    col[i + x + 1][j] -= 1
                    row[i][j - x] += 1
                    row[i][j + x + 1] -= 1
    
    for i in range(n):
        for j in range(m):
            row[i][j + 1] += row[i][j]
            col[i + 1][j] += col[i][j]
            
    for i in range(n):
        for j in range(m):
            if S[i][j] == "*":
                if row[i][j] == 0 and col[i][j] == 0:
                    print(-1)
                    return
    
    print(len(ans))
    for row in ans:
        print(*row)
    
    
for _ in range(1):
    main()