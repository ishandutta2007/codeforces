import sys
input = sys.stdin.readline

def main():
    n = int(input())
    ans = []
    times = 1
    while n > 0:
        if n % 10 != 0:
            ans.append(n % 10 * times)
        times *= 10
        n //= 10
    print(len(ans))
    print(*ans)
    
for _ in range(int(input())):
    main()