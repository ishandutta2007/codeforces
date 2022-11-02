n = int(input())
a = input()
ans=''
for i in range(1, n):
    if a[i-1] != a[i]:
        ans = a[i-1] + a[i]
if len(ans) > 0:
    print('YES')
    print(ans)
else:
    print('NO')