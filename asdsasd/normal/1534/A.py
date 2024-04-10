import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    grid = [list(input().strip()) for _ in range(n)]
    r = -1
    w = -1
    for i in range(n):
        for j in range(m):
            if grid[i][j] == "R":
                x = (i + j) % 2
                if r == -1:
                    r = x
                elif r != x:
                    print("NO")
                    return
            elif grid[i][j] == "W":
                x = (i + j) % 2
                if w == -1:
                    w = x
                elif w != x:
                    print("NO")
                    return
    if r == w == -1:
        r = 0
        w = 1
    elif r == -1:
        r = 1 - w
    elif w == -1:
        w = 1 - r
    elif r == w:
        print("NO")
        return
    print("YES")
    for i in range(n):
        for j in range(m):
            if (i + j) % 2 == r:
                grid[i][j] = "R"
            else:
                grid[i][j] = "W"
        print(*grid[i], sep="")
    
for _ in range(int(input())):
    main()