import sys
input = sys.stdin.readline

def main():
    n = int(input())
    ans = list(range(2, n + 2))
    print(*ans)
    
for _ in range(int(input())):
    main()