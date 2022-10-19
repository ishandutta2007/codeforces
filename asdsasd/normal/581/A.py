import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    print(min(n, m), abs(n - m) // 2)

main()
"""
for _ in range(int(input())):
    main()
"""