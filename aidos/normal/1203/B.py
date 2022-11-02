t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().split()))
    bad = 0
    s = set()
    for i in range(n):
        if a[2*i] != a[2*i+1] or a[4*n-2*i-1] != a[4*n-2*i-2]:
            bad = 1
        s.add(a[2*i] * a[4*n-2*i-1])
    if bad or len(s)>1:
        print('NO')
    else:
        print('YES')