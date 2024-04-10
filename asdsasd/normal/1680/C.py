import sys
input = sys.stdin.readline

def main():
    S = input().strip().strip("0")
    if len(set(S)) <= 1:
        print(0)
        return    
    cum = [0]
    tot = 0
    for s in S:
        if s == "1":
            cum.append(cum[-1] + tot)
            tot = 0
        else:
            tot += 1
    cum = cum[1:]
    le = len(cum)
    def ok(mid):
        mi = 1 << 30
        for i in range(mid + 1):
            mi = min(mi, cum[le - 1 - mid + i] - cum[i])
        return mi <= mid

    l = -1
    r = len(cum)
    while r - l > 1:
        mid = (l + r) // 2
        if ok(mid):
            r = mid
        else:
            l = mid
    print(r)
    
for _ in range(int(input())):
    main()