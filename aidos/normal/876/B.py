n, k, m = map(int, input().split())
a = list(map(int, input().split()))
b = dict()
x = -1
for i in a:
    b[i%m] = b.get(i % m, 0) + 1
for e, f in b.items():
    if f >= k:
        x = e
if x != -1:
    print('Yes')
    for i in a:
        if k > 0 and i % m == x:
            print(i, end=' ')
            k -= 1
else:
    print('No')