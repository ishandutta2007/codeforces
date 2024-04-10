import sys
input = sys.stdin.readline

def main():
    n, u, v = map(int, input().split())
    alst = list(map(int, input().split()))
    bef = alst[0]
    flg = False
    for a in alst[1:]:
        if abs(a - bef) > 1:
            print(0)
            return
        elif abs(a - bef) == 1:
            flg = True
        bef = a
    if flg:
        ans = min(u, v)
    else:
        ans = v + min(u, v)
    print(ans)
                
    
for _ in range(int(input())):
    main()