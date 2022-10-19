import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    xy = [list(map(int, input().split())) for _ in range(n)]
    for i in range(n):
        flg = True
        xi, yi = xy[i]
        for x, y in xy:
            if abs(x - xi) + abs(y - yi) > k:
                flg = False
                break
        if flg:
            print(1)
            return
    print(-1)
    
for _ in range(int(input())):
    main()