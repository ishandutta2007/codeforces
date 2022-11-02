n = int(input())
a = []
for i in range(n):
    x = input()
    a.append([len(x), x])
a = sorted(a)
cnt = 0
for i in range(1, n):
    if a[i-1][1] in a[i][1]:
        cnt += 1
if cnt == n-1:
    print('YES')
    for i in range(n):
        print(a[i][1])
else:
    print('NO')