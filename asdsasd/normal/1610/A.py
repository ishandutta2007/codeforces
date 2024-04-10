import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    if n == 1 and m == 1:
        print(0)
    elif n == 1 or m == 1:
        print(1)
    else:
        print(2)
    
for _ in range(int(input())):
    main()