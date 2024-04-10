import sys
input = sys.stdin.readline

def main():
    n = int(input())
    if n % 2 == 1:
        print("NO")
        return
    n //= 2
    if n == int(n ** 0.5) ** 2:
        print("YES")
        return
    if n % 2 == 1:
        print("NO")
        return
    n //= 2
    if n == int(n ** 0.5) ** 2:
        print("YES")
        return
    print("NO")
        

        
for _ in range(int(input())):
    main()