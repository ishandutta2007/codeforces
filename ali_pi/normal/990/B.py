rd = lambda: map(int,raw_input().split())
n, k = rd()
a = sorted(rd())
r, t = 0, 0
l = -1e20
for i in range(n):
    if a[i] > l + k:
        r += t
        t = 1
    elif a[i] == l:
        t += 1
    else:
        t = 1
    l = a[i]
print(r + t)