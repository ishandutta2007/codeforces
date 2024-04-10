q = int(input())
for tc in range(q):
    n = int(input())
    arr = list(map(int, input().split(' ')))
    nw = 0
    while nw<n:
        mi = min(arr[nw:])
        pl = arr.index(mi)
        arr = arr[:nw] + [arr[pl]] + arr[nw:pl] + arr[pl+1:]
        if nw == pl:
            nw += 1
        else:
            nw = pl
    print(*arr)