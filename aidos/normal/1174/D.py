n, x = map(int, input().split())
m = 2 ** n
a = [0] * (2**18)
b = []
for i in range(m):
    if a[i] == 0:
        a[i] = 1
        a[i^x] = 1
        b.append(i)
print(len(b)-1)
for i in range(1, len(b)):
    print(b[i]^b[i-1], end = ' ')