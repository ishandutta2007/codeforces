import sys
input = sys.stdin.readline

def main():
    n, m, k = map(int, input().split())
    x = n * m // 2 - k
    grid = [["."] * m for _ in range(n)]
    if n % 2 == 0 and m % 2 == 0:
        if k % 2 == 1:
            print("NO")
            return
        print("YES")
        for i in range(0, n, 2):
            for j in range(0, m, 2):
                if (i + j) % 4 == 2:
                    a = "a"
                    b = "b"
                else:
                    a = "c"
                    b = "d"
                if k:
                    k -= 2
                    grid[i][j] = a
                    grid[i][j + 1] = a
                    grid[i + 1][j] = b
                    grid[i + 1][j + 1] = b
                else:
                    grid[i][j] = a
                    grid[i][j + 1] = b
                    grid[i + 1][j] = a
                    grid[i + 1][j + 1] = b
        
        for row in grid:
            print("".join(row))
        
        return
    if n % 2 == 0:
        if x < n // 2:
            print("NO")
            return
        x -= n // 2
        if x % 2 == 1:
            print("NO")
            return
        for i in range(0, n, 2):
            if i % 4 == 2:
                a = "e"
            else:
                a = "f"
            grid[i][0] = a
            grid[i + 1][0] = a
        print("YES")
        for i in range(0, n, 2):
            for j in range(1, m, 2):
                if (i + j) % 4 == 1:
                    a = "a"
                    b = "b"
                else:
                    a = "c"
                    b = "d"
                if k:
                    k -= 2
                    grid[i][j] = a
                    grid[i][j + 1] = a
                    grid[i + 1][j] = b
                    grid[i + 1][j + 1] = b
                else:
                    grid[i][j] = a
                    grid[i][j + 1] = b
                    grid[i + 1][j] = a
                    grid[i + 1][j + 1] = b
        
        for row in grid:
            print("".join(row))
        
        return
    
    else:
        if k < m // 2:
            print("NO")
            return
        k -= m // 2
        if x % 2 == 1:
            print("NO")
            return
        for j in range(0, m, 2):
            if j % 4 == 2:
                a = "e"
            else:
                a = "f"
            grid[0][j] = a
            grid[0][j + 1] = a
        print("YES")
        for i in range(1, n, 2):
            for j in range(0, m, 2):
                if (i + j) % 4 == 1:
                    a = "a"
                    b = "b"
                else:
                    a = "c"
                    b = "d"
                if k:
                    k -= 2
                    grid[i][j] = a
                    grid[i][j + 1] = a
                    grid[i + 1][j] = b
                    grid[i + 1][j + 1] = b
                else:
                    grid[i][j] = a
                    grid[i][j + 1] = b
                    grid[i + 1][j] = a
                    grid[i + 1][j + 1] = b
        
        for row in grid:
            print("".join(row))
        
        return
    
for _ in range(int(input())):
    main()