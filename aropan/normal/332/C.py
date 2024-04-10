import random

n, p, k =  map(int, raw_input().split())
a = []
for i in xrange(n):
    a.append(map(int, raw_input().split()))
    a[i][1] = -a[i][1]
b = sorted(range(n), key=lambda x: (a[x][1], a[x][0]))
ans = []
if p != k:
    ans = b[-(p - k):]
    b = b[:-(p - k)]

b.sort(key=lambda x: (-a[x][0], a[x][1]))
c = b[k:]
b = b[:k]
b.sort(key=lambda x: (a[x][1], a[x][0]))
ans = [i for i in ans + c if a[b[k - 1]][1] < a[i][1] or a[b[k - 1]][1] == a[i][1] and a[b[k - 1]][0] <= a[i][0]]
ans.sort(key=lambda x: a[x][1])
ans = ans[:p-k]
ans += b;
print ' '.join(str(i + 1) for i in ans)