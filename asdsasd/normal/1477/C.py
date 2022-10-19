import sys
input = sys.stdin.readline
from math import gcd

def main():
    n = int(input())
    points = [tuple(map(int, input().split())) for _ in range(n)]
    ans = [i for i in range(n)]
    
    def ng(i):
        x1, y1 = points[ans[i - 1]]
        x2, y2 = points[ans[i]]
        x3, y3 = points[ans[i + 1]]
        dx1, dy1 = abs(x1 - x2), abs(y1 - y2)
        dx2, dy2 = abs(x2 - x3), abs(y2 - y3)
        dx3, dy3 = abs(x1 - x3), abs(y1 - y3)
        d1 = dx1 ** 2 + dy1 ** 2
        d2 = dx2 ** 2 + dy2 ** 2
        d3 = dx3 ** 2 + dy3 ** 2
        return d3 >= d1 + d2
    
    flg = True
    while flg:
        flg = False
        for i in range(1, n - 1):
            if ng(i):
                ans[i], ans[i + 1] = ans[i + 1], ans[i]
                flg = True
    
    for i in range(n):
        ans[i] += 1
    print(*ans)
    
    
for _ in range(1):
    main()