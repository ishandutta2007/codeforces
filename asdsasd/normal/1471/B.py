import sys
input = sys.stdin.readline

def main():
    n, x = map(int, input().split())
    alst = list(map(int, input().split()))
    ans = sum(alst)
    b = x
    while 1:
        for a in alst:
            if a % b == 0:
                ans += a
            else:
                break
        else:
            b *= x
            continue
        break
    print(ans)
    
for _ in range(int(input())):
    main()