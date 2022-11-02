n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
a = sorted(a)
if a[0] == a[n//2-1] and a[n//2] == a[n-1] and a[0] != a[n-1]:
    print("YES")
    print(a[0], a[-1])
else:
    print('NO')