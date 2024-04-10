import math

n = int(input())
a = []
x = 1
y = 1
for i in range(1, n):
    if math.gcd(i, n) == 1:
        a.append(i)
        y = x
        x = x * i % n
if x != 1 and y == 1:
    a = a[:-1]
print(len(a))
for x in a:
    print(x, sep=' ')