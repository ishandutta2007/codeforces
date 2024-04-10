import sys
input = sys.stdin.readline

def main():
    n, m, K = map(int, input().split())
    A = [list(map(int, input().split())) for _ in range(n)]
    dp1 = [[{} for _ in range(m)] for _ in range(n)]
    dp2 = [[{} for _ in range(m)] for _ in range(n)]
    dp1[0][0] = {A[0][0]:1}
    dp2[-1][-1] = {A[-1][-1]:1}
    half = (n + m - 1) // 2
    for i in range(n):
        for j in range(m):
            if i + j > half:
                break
            if i != 0:
                for k, v in dp1[i - 1][j].items():
                    dp1[i][j][k ^ A[i][j]] = dp1[i][j].get(k ^ A[i][j], 0) + v
            if j != 0:
                for k, v in dp1[i][j - 1].items():
                    dp1[i][j][k ^ A[i][j]] = dp1[i][j].get(k ^ A[i][j], 0) + v
    for i in range(n - 1, -1, -1):
        for j in range(m - 1, -1, -1):
            if i + j < half:
                break
            if i != n - 1:
                for k, v in dp2[i + 1][j].items():
                    dp2[i][j][k ^ A[i][j]] = dp2[i][j].get(k ^ A[i][j], 0) + v
            if j != m - 1:
                for k, v in dp2[i][j + 1].items():
                    dp2[i][j][k ^ A[i][j]] = dp2[i][j].get(k ^ A[i][j], 0) + v
    ans = 0
    for i in range(n):
        j = half - i
        if j < 0 or j >= m:
            continue
        for k, v in dp1[i][j].items():
            ans += v * dp2[i][j].get(k ^ A[i][j] ^ K, 0)
    print(ans)
    
for _ in range(1):
    main()