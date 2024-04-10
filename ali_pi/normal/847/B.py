n = int(raw_input())
from bisect import bisect_left
a = list(map(int, raw_input().split()))
ss = []
ms = []
for i in range(n):
    k = a[i]
    ind = bisect_left(ms, -k)
    if ind == len(ms):
        ss.append([])
        ms.append(0)
    ss[ind].append(k)
    ms[ind] = -k
for s in ss:
    print(' '.join([str(i) for i in s]))