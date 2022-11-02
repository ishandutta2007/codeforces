n, k = map(int, input().split())
a = list(map(int, input().split()))
b = []
c = []
for i in range(n):
    if len(b) < k and a[i] not in b:
        b.append(a[i])
        c.append(i+1)
if len(b) == k:
    print("YES")
    for i in c:
        print(i, end = ' ')
else:
    print('NO')