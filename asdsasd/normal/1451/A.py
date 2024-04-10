import sys
input = sys.stdin.readline

def main():
    ans = 0
    n = int(input())
    if n == 1:
        print(0)
    elif n == 2:
        print(1)
    elif n == 3 or n % 2 == 0:
        print(2)
    else:
        print(3)
    
for _ in range(int(input())):
    main()