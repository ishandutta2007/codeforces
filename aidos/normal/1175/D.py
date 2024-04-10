n, k = map(int, input().split())
a = list(map(int, input().split()))
b = []
s = 0
for x in a[::-1]:
    s += x
    b.append(-s)
if k == 1:
    print(-b[-1])
else:
    d = sorted(b[:-1])
    print(-sum(d[:k-1]) - b[-1])