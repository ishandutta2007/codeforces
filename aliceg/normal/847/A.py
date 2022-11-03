n = int(input())

if n == 1:
    print(0, 0)
    exit()

a = []
for i in range(n):
    a.append(list(map(int, input().split())))

s = []
i = 0
while i < n:
    if a[i][0] == 0:
        k = i
        s.append([i + 1])
        while a[k][1] != 0:
            k = a[k][1] - 1
            s[-1].append(k + 1)
    i += 1

p = []
for i in s:
    p.extend(i)

for i in range(n):
    if i == 0:
        a[p[i] - 1] = [0, p[1]]
    elif i == n - 1:
        a[p[i] - 1] = [p[i - 1], 0]
    else:
        a[p[i] - 1] = [p[i - 1], p[i + 1]]

for i in a:
    print(i[0], i[1])