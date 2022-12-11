inp = list(map(int, input().split()))
dist = lambda x1, y1, x2, y2: (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)
n = inp[0]
x1 = inp[1]
y1 = inp[2]
x2 = inp[3]
y2 = inp[4]
a = list()
for i in range(n):
    a.append(list(map(int, input().split())))
    a[i].append(dist(x1, y1, a[i][0], a[i][1]));
    a[i].append(dist(x2, y2, a[i][0], a[i][1]));
    a[i][0], a[i][2] = a[i][2], a[i][0]
    a[i][1], a[i][2] = a[i][2], a[i][1]
a.sort()

ans = 2**64
lf = 0 
for i in range(-1, n):
    lf = max(lf, 0 if i == -1 else a[i][0])
    rg = 0
    for j in range(i + 1, n):
        rg = max(rg, a[j][3])
    ans = min(ans, lf + rg)
    
print(ans)

import time, sys
sys.stderr.write('{0:.3f} ms\n'.format(time.clock() * 1000));

# by Andrey Kim