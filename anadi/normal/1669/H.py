cases = int(input())

while cases > 0:
    cases -= 1
    
    n, k = [int(x) for x in input().split()]
    vals = [int(x) for x in input().split()]

    missing = [n] * 31
    for i in range(n):
        for p in range(31):
            if vals[i] >> p & 1:
                missing[p] -= 1
    
    ans = 0
    for p in range(30, -1, -1):
        if missing[p] <= k:
            k -= missing[p]
            ans |= 1 << p
    print(ans)