from operator import attrgetter
from collections import namedtuple

n, t = tuple(int(i) for i in raw_input().split())
a = tuple(int(i) for i in raw_input().split())

ans = False

c = 0
t = t - 1
if t == 0:
    ans = True
while c < n - 1:
    c += a[c]
    if c == t:
        ans = True

print "YES" if ans else "NO"