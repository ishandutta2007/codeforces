import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    ans = [1] * (k - 3)
    n -= k - 3
    times = 1
    while n % 2 == 0 and n >= 4:
        n //= 2
        times *= 2
    if n == 2:
        print(*ans, times, times // 2, times // 2)
    else:
        print(*ans, times, n // 2 * times, n // 2 * times)
    
    
for _ in range(int(input())):
    main()