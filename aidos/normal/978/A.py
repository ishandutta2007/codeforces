n = int(input())
a = list(map(int, input().split()))
b = []
for i in range(n):
    if a[i] in b:
        b.remove(a[i])
    b.append(a[i])
print(len(b))
for i in b:
    print(i, end = ' ')