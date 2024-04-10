import sys
input = sys.stdin.readline

def main():
    n, m, r, c = map(int, input().split())
    n -= 1
    m -= 1
    r -= 1
    c -= 1
    ans = max(r, n - r) + max(c,  m - c)
    print(ans)
    
for _ in range(int(input())):
    main()