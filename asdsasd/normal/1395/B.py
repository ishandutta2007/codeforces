import sys
input = sys.stdin.buffer.readline

def main():
    n, m, sx, sy = map(int, input().split())
    print(sx, sy)
    for i in range(1, m + 1):
        if i == sy:
            continue
        print(sx, i)
    d = -1
    y = i
    for j in range(1, n + 1):
        if j == sx:
            continue
        print(j, y)
        for _ in range(m - 1):
            y += d
            print(j, y)
        d *= -1
    
    
"""
t = int(input())    
for _ in range(t):
    main()
"""
main()