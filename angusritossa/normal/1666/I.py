def scan(i,j):
    print("SCAN",i,j,flush=True)
    return int(input())

def dig(i,j):
    print("DIG",i,j,flush=True)
    return int(input())

t = int(input())
for casen in range(t):
    n,m = list(map(int,input().strip().split()))
    s11 = scan(1,1)
    s1m = scan(1,m)
    sn1 = 2*(n-1)+2*(m-1)-s1m
    sx = (s11+s1m-2*(m-1)+4)//2
    sy = (s11+sn1-2*(n-1)+4)//2
    my = sy//2
    mx = sx//2
    smy = scan(1,my) - (sx-2)
    smx = scan(mx,1) - (sy-2)
    # y1+y2 = sy, abs(y1-y2) = smy
    # 2y1 = sy+smy, y1 = (sy+smy)/2, y2 = (sy-smy)/2
    y1 = (sy+smy)//2
    y2 = (sy-smy)//2
    x1 = (sx+smx)//2
    x2 = (sx-smx)//2
    if dig(x1,y1):
        assert(dig(x2,y2))
    else:
        assert(dig(x1,y2))
        assert(dig(x2,y1))