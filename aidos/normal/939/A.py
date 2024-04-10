n = int(input())
a = list(map(int, input().split()))
for i in range(n):
    a[i] -= 1
ans = 0
for i in range(n):
    if a[a[a[i]]] == i:
        ans += 1
if ans > 0:
    print('YES')
else:
    print('NO')