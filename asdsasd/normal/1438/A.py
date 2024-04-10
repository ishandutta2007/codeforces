import sys
input = sys.stdin.readline

def main():
    n = int(input())
    ans = [1] * n
    print(*ans)
    
for _ in range(int(input())):
    main()