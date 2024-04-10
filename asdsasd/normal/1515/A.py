import sys
input = sys.stdin.readline

def main():
    n, x = map(int, input().split())
    wlst = list(map(int, input().split()))
    total = sum(wlst)
    if total == x:
        print("NO")
        return
    se = set(wlst)
    if len(se) == 1:
        if total >= x and x % wlst[0] == 0:
            print("NO")
            return
        
    print("YES")
    
    if len(wlst) == 1:
        print(*wlst)
        return
    elif len(wlst) == 2:
        if wlst[0] == x:
            wlst = wlst[::-1]
        print(*wlst)
        return
    wlst.sort()
    min_ = wlst[0]
    max_ = wlst[-1]
    wlst = wlst[1:-1]
    ans = []
    tot = 0
    for w in wlst:
        tot += w
        if tot == x:
            if w == min_:
                ans.append(max_)
                max_ = -1
            else:
                ans.append(min_)
                min_ = -1
        ans.append(w)
    if max_ != -1 and min_ != -1:
        if tot + max_ == x:
            ans.append(min_)
            ans.append(max_)
        else:
            ans.append(max_)
            ans.append(min_)
    else:
        if max_ != -1:
            ans.append(max_)
        elif min_ != -1:
            ans.append(min_)
    print(*ans)
        
for _ in range(int(input())):
    main()