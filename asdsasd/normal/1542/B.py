import sys
input = sys.stdin.readline

def main():
    n, a, b = map(int, input().split())
    if a == 1:
        if (n - 1) % b == 0:
            print("Yes")
        else:
            print("No")
        return
    x = 1
    while x <= n:
        if (n - x) % b == 0:
            print("Yes")
            return
        x *= a
    print("No")
        
        
    
for _ in range(int(input())):
    main()