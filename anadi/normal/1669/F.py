cases = int(input())

while cases > 0:
    cases -= 1
    
    n = int(input())
    vals = [int(x) for x in input().split()]

    ans = 0
    s = sum(vals)

    pref, suf = 0, 0
    suf_ptr = n - 1

    for i in range(n):
        pref += vals[i]
        if pref + pref > s:
            break
        
        while suf < pref:
            suf += vals[suf_ptr]
            suf_ptr -= 1
        
        if suf == pref:
            ans = i + n - suf_ptr
    
    print(ans)