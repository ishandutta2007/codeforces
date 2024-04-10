import sys
input = sys.stdin.readline

def main():
    n = int(input())
    C = [list(map(int, input().split())) for _ in range(2 * n)]
    ans = 0
    for i in range(n, 2 * n):
        for j in range(n, 2 * n):
            ans += C[i][j]
    min_ = min(C[0][-1], C[0][n], C[n - 1][-1], C[n - 1][n])
    min_ = min(min_, C[-1][0], C[n][0], C[-1][n - 1], C[n][n - 1])
        
            
    print(ans + min_)

for _ in range(int(input())):
    main()