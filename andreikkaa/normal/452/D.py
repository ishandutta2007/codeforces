k, na, nb, nc, ta, tb, tc = list(map(int, input().split()))
from collections import deque

a = deque()
b = deque()
c = deque()

for i in range(na):
        a.append(0)
for i in range(nb):
        b.append(0)
for i in range(nc):
        c.append(0)

t = 0
for i in range(k):
        vr = max(a[0], b[0] - ta, c[0] - (ta + tb))
        a.popleft()
        a.append(vr + ta)
        b.popleft()
        b.append(vr + tb + ta)
        c.popleft()
        c.append(vr + ta + tb + tc)
        t = vr + ta + tb + tc
print(t)