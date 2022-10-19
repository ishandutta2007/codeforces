import sys
input = sys.stdin.readline

def main():
    h, w = map(int, input().split())
    grid = [[0] * w for _ in range(h)]
    for j in range(0, w, 2):
        grid[0][j] = 1
        grid[-1][j] = 1
    
    for i in range(2, h - 2, 2):
        grid[i][0] = 1
        grid[i][-1] = 1
    
    for row in grid:
        print(*row, sep = "")
    print()
            
for _ in range(int(input())):
    main()