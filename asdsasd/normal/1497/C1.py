import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    times = 1
    while n % 2 == 0 and n >= 4:
        n //= 2
        times *= 2
    if n == 2:
        print(times, times // 2, times // 2)
    else:
        print(times, n // 2 * times, n // 2 * times)
    
    
for _ in range(int(input())):
    main()