import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    alst = [list(map(int, input().split())) for _ in range(n)]
    blst = [[0 for _ in range(m)] for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if (i + j) % 2 == alst[i][j] % 2:
                blst[i][j] = alst[i][j]
            else:
                blst[i][j] = alst[i][j] + 1
    for row in blst:
        print(*row)
    
for _ in range(int(input())):
    main()