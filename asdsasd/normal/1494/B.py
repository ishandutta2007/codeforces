import sys
input = sys.stdin.readline

def main():
    n, u, r, d, l = map(int, input().split())
    
    for ur in (True, False):
        for dr in (True, False):
            for ul in (True, False):
                for dl in (True, False):
                    uu = u
                    rr = r
                    ll = l
                    dd = d
                    if ur:
                        uu -= 1
                        rr -= 1
                    if dr:
                        dd -= 1
                        rr -= 1
                    if ul:
                        uu -= 1
                        ll -= 1
                    if dl:
                        dd -= 1
                        ll -= 1
                    flg = True
                    for s in (uu, dd, rr, ll):
                        if s < 0 or s > n - 2:
                            flg = False
                            break
                    if flg:
                        print("YES")
                        return
    print("NO")
    
for _ in range(int(input())):
    main()