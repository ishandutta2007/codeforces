import sys
input = sys.stdin.readline

def main():
    n = int(input())
    k = int(n ** 0.5)
    n -= k ** 2
    ans = 2 * (k - 1) + 1
    if n > k:
        ans += 1
    if n == 0:
        ans -= 1
    print(ans)
    
for _ in range(int(input())):
    main()