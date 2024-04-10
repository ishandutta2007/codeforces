n, m = map(int, input().split())
a = []
for i in range(n):
    a.append(list(input()))

for i in range(n):
    for j in range(m):
        if i + 1 < n and (a[i][j] + a[i+1][j]) in ('SW', 'WS'):
            print('No')
            exit(0)
        if j + 1 < m and (a[i][j] + a[i][j+1]) in ('SW', 'WS'):
            print('No')
            exit(0)
print('Yes')
for i in range(n):
    print(''.join(map(lambda x: x.replace('.', 'D'), a[i])))