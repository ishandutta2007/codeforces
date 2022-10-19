import sys
input = sys.stdin.readline

def main():
    n, x = map(int, input().split())
    last = 2
    ans = 1
    while last < n:
        last += x
        ans += 1
    print(ans)
    
    
for _ in range(int(input())):
    main()