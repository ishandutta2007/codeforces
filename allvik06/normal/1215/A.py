a1 = int(input())
a2 = int(input())
k1 = int(input())
k2 = int(input())
n = int(input())
m = n
max0 = 0
a = []
for i in range(a1 + a2):
    if i < a1:
        a.append(k1)
    else:
        a.append(k2)
a.sort()
for i in range(a1 + a2):
    if n >= a[i]:
        n -= a[i]
        max0+= 1
for i in range(a1 + a2):
     m -= a[i] - 1
print(max(m, 0), end=" ")
print(max0)