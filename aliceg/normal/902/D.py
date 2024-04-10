n = int(input())
a = [1]
b = [0]
for i in range(n):
    c = a.copy()
    a.append(0)
    for i in range(len(a) - 1, 0, -1):
        a[i] = a[i - 1]
        if i < len(b):
            a[i] += b[i]
        a[i] %= 2
    a[0] = b[0]
    b = c.copy()

print(len(a) - 1)
for i in a:
    print(i, end=' ')
print('')

print(len(b) - 1)
for i in b:
    print(i, end=' ')