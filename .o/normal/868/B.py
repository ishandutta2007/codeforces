h,m,s,t1,t2=map(int,input().split())
h%=12
t1%=12
t2%=12
angles = sorted([
    ((3600 * h + 60 * m + s), 0),
    ((60 * m + s) * 12, 0),
    (s * 12 * 60, 0),
    (3600 * t1, 1),
    (3600 * t2, 2)
])
x = [v[1] for v in angles]
good = False
for i in range(len(angles)):
    for j in range(i+1, len(angles)):
        if x[i] + x[j] == 3:
            good |= all(x[k] != 0 for k in range(i+1, j))
            good |= \
                all(x[k] != 0 for k in range(j+1, len(angles))) and \
                all(x[k] != 0 for k in range(0, i))

print("YES" if good else "NO")