import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    alst = list(map(int, input().split()))
    for i, a in enumerate(alst[::-1]):
        if a != n - i:
            break
    else:
        print(1)
        for _ in range(m):input()
        return
    ind = n - i
    ans = 1
    for _ in range(m):
        r, p = input().split()
        r = int(r)
        p = float(p)
        if r >= n - i:
            ans *= (1 - p)
    print(1 - ans)
    
for _ in range(int(input())):
    main()