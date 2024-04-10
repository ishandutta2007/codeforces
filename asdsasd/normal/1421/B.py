import sys
input = sys.stdin.readline

def main():
    n = int(input())
    maze = [input().strip() for _ in range(n)]
    ans = []
    if maze[0][1] == "0":
        ans.append((1, 2))
    if maze[1][0] == "0":
        ans.append((2, 1))
    if maze[n - 1][n - 2] == "1":
        ans.append((n, n - 1))
    if maze[n - 2][n - 1] == "1":
        ans.append((n - 1, n))
    if len(ans) <= 2:
        print(len(ans))
        for row in ans:
            print(*row)
        return
    ans = []
    if maze[0][1] == "1":
        ans.append((1, 2))
    if maze[1][0] == "1":
        ans.append((2, 1))
    if maze[n - 1][n - 2] == "0":
        ans.append((n, n - 1))
    if maze[n - 2][n - 1] == "0":
        ans.append((n - 1, n))
    if len(ans) <= 2:
        print(len(ans))
        for row in ans:
            print(*row)
    
for _ in range(int(input())):
    main()