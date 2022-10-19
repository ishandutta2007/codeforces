import sys
input = sys.stdin.readline

def main():
    a, b = map(int, input().split())
    if a == b:
        print(0, 0)
        return
    else:
        x = abs(a - b)
        y = min(a % x, x - a % x)
        print(x, y)
    
for _ in range(int(input())):
    main()