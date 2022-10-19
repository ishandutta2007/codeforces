import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    total = 0
    ans = 0
    for a in alst:
        total -= a
        ans = max(ans, total)
    print(ans)
    
main()
"""
for _ in range(int(input())):
    main()
"""