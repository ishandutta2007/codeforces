n = int(input())
a = []
for i in range(n):
    x, y = map(int, input().split())
    a.append(x)
a = sorted(a)
if a[-2] * a[0] > 0 or a[-1] * a[1] > 0:
    print("YES")
else:
    print("NO")