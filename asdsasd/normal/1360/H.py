def solve():
    n, m = map(int, input().split())
    a_s = [int(input(), 2) for _ in range(n)]
    total = 2 ** m - n
    med = (total + 1) // 2
    l = -1
    r = 2 ** m
    while r - l > 1:
        mid = (r + l) // 2
        cnt = mid + 1
        for a in a_s:
            if a <= mid:
                cnt -= 1
        if cnt >= med:
            r = mid
        else:
            l = mid
    print(format(r, "b").zfill(m))
        
    
    
    
    
for _ in range(int(input())):
    solve()