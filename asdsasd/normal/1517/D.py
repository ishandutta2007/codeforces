import sys
input = sys.stdin.readline
from collections import deque

def main():
    n, m, k = map(int, input().split())
    if k % 2 == 1:
        for _ in range(n):
            print(*[-1] * m)
        return
    
    k //= 2
    dj = [list(map(int, input().split())) for _ in range(n)]
    di = [list(map(int, input().split())) for _ in range(n - 1)]
    inf = 10 ** 20
    dist = [[inf] * (k + 1) for _ in range(n * m)]
    for i in range(n * m):
        dist[i][0] = 0

    for kk in range(k):
        for i in range(n):
            for j in range(m):
                x = i * m + j
                
                if j != 0:
                    dist[x][kk + 1] = min(dist[x][kk + 1], dist[x - 1][kk] + dj[i][j - 1])
            
                if j != m - 1:
                    dist[x][kk + 1] = min(dist[x][kk + 1], dist[x + 1][kk] + dj[i][j])
                if i != 0:
                    dist[x][kk + 1] = min(dist[x][kk + 1], dist[x - m][kk] + di[i - 1][j])
                if i != n - 1:
                    dist[x][kk + 1] = min(dist[x][kk + 1], dist[x + m][kk] + di[i][j])
                
    ans = [[-1] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            ans[i][j] = dist[i * m + j][-1] * 2
    for row in ans:
        print(*row)
            
                
            
    
            
    
    
for _ in range(1):
    main()