h = int(input())
a = list(map(int, input().split()))
k = 0
for i in range(h):
    if a[i] > 1 and a[i + 1] > 1:
        k = i + 1
        break
else:
    print('perfect')
    exit()
print('ambiguous')

h1 = 1
p = 1
print(0, end=' ')
while h1 <= h:
    for i in range(a[h1]):
        print(p, end=' ')
    p += a[h1 - 1]
    h1 += 1
print('')

h1 = 1
p = 1
print(0, end=' ')
while h1 <= h:
    if h1 == k:
        for i in range(a[h1] - 1):
            print(p, end=' ')
        print(p + 1, end=' ')
        p += a[h1 - 1]
        h1 += 1
        continue
    for i in range(a[h1]):
        print(p, end=' ')
    p += a[h1 - 1]
    h1 += 1