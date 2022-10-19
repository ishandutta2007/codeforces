import sys
input = sys.stdin.readline

def main():
    n, k, x = map(int, input().split())
    alst = list(map(int, input().split()))
    alst.sort()
    ans = 1
    lst = []
    bef = alst[0]
    for a in alst[1:]:
        d = a - bef
        if d > x:
            ans += 1
            lst.append((d - 1) // x)
        bef = a
    lst.sort()
    lst += [10 ** 50]
    
    for l in lst:
        if l <= k:
            k -= l
            ans -= 1
        else:
            break
    print(ans)
    
for _ in range(1):
    main()