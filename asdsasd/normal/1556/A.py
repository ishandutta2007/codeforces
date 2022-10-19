import sys
input = sys.stdin.readline

def main():
    c, d = map(int, input().split())
    if (c + d) % 2 == 1:
        print(-1)
    elif c == d == 0:
        print(0)
    elif c == d:
        print(1)
    else:
        print(2)
    
for _ in range(int(input())):
    main()