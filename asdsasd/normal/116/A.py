import sys
input = sys.stdin.readline

def main():
    n = int(input())
    ans = 0
    total = 0
    for _ in range(n):
        a, b = map(int, input().split())
        total += b - a
        ans = max(ans, total)
    print(ans)

main()