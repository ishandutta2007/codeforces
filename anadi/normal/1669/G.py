cases = int(input())

while cases > 0:
    cases -= 1
    
    n, m = [int(x) for x in input().split()]
    grid = []
    
    for _ in range(n):
        grid.append(input())
    
    result = [['.'] * m for _ in range(n)]
    for col in range(m):
        last = n
        for r in range(n - 1, -1, -1):
            if grid[r][col] == 'o':
                result[r][col] = 'o'
                last = r
            elif grid[r][col] == '*':
                last -= 1
                result[last][col] = '*'
    
    for row in result:
        for cell in row:
            print(cell, end="")
        print("")