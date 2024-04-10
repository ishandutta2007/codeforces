import sys
input = sys.stdin.readline

def main():
    n = int(input())
    bef_grid = [list(map(int, input().strip())) for _ in range(n)]
    input()
    aft_grid = [list(map(int, input().strip())) for _ in range(n)]
    row = []
    for i in range(n):
        if bef_grid[i][0] != aft_grid[i][0]:
            row.append(i)
    for i in row:
        for j in range(n):
            bef_grid[i][j] ^= 1
    for j in range(n):
        if bef_grid[0][j] != aft_grid[0][j]:
            for i in range(n):
                bef_grid[i][j] ^= 1
    print("YES" if bef_grid == aft_grid else "NO")
    
    
for _ in range(int(input())):
    main()