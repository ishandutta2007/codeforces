import sys
input = sys.stdin.readline

def main():
    n = int(input())
    if n == 1:
        print("a")
        return
    elif n % 2 == 0:
        print("a" * (n // 2) + "b" + "a" * (n // 2 - 1))
    else:
        print("a" * (n // 2) + "bc" + "a" * (n // 2 - 1))
    
for _ in range(int(input())):
    main()