cases = int(input())

for case in range(cases):
    n = int(input())
    vals = [int(x) for x in input().split()]

    ok = 1
    for r in range(2):
        for c in range(r + 2, n, 2):
            ok &= vals[r] % 2 == vals[c] % 2
    
    if ok:
        print("YES")
    else:
        print("NO")