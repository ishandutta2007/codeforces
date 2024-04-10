n = int(input())
a = list(map(int, input().split()))
x = max(a)
b = []
c = []
for i in range(n):
    if x % a[i] == 0:
        if a[i] in b:
            c.append(a[i])
        else:
            b.append(a[i])
    else:
        c.append(a[i])
print(x, max(c))