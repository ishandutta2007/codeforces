import sys
input = sys.stdin.readline

def main():
    n = int(input())
    ans = [i for i in range(1, n + 1)]
    print(*ans)

for _ in range(int(input())):
    main()