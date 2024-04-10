a = [0]*2750132
b = [0]*2750132
for i in range(2, 2750132):
    if a[i] == 0:
        for j in range(i * i, 2750132, i):
            if a[j] == 0:
                a[j] = i
ind = 1
for i in range(2, 2750132):
    if a[i] == 0:
        b[i] = ind
        ind += 1

n = int(input())
z = sorted(map(int, input().split()))
d = dict()
for x in z[::-1]:
    if d.get(x, 0) == 0:
        if a[x] == 0:
            print(b[x], end=' ')
            d[b[x]] = d.get(b[x], 0) + 1
        else:
            print(x, end=' ')
            d[x//a[x]] = d.get(x//a[x], 0) + 1
    else:
        d[x] = d.get(x,0) - 1