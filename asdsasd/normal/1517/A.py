import sys
input = sys.stdin.readline

def main():
    n = int(input())
    x = 2050
    while x < n:
        x *= 10
    cnt = 0
    while x >= 2050:
        cnt += n // x
        n %= x
        x //= 10
    if n == 0:
        print(cnt)
    else:
        print(-1)
    
    
    
for _ in range(int(input())):
    main()