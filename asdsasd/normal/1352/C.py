import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    if k % (n - 1) == 0:
        print(k // (n - 1) * n - 1)
    else:
        print(k // (n - 1) * n + k % (n - 1))
    
for _ in range(int(input())):
    main()