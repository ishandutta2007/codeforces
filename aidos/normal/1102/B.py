n, k = map(int, input().split())
a = list(map(int, input().split()))
b = []
for j in range(5002):
    b.append([])
j = 0
for i in range(n):
    b[a[i]].append(i)
c = [0] * n
good = 1
for x in b:
    if len(x) > k:
        good = 0
    for t in x:
        c[t] = j + 1
        j = (j + 1) % k

if good == 1:
    print("YES")
    for i in c:
        print(i, end = ' ')
else:
    print("NO")