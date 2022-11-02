n = int(input())
a = list(map(int, input().split()))
b = []
mx = -(10**10)
for i in range(n-1, -1, -1):
    b.append(max(0, mx+1-a[i]))
    mx = max(mx, a[i])
b = b[::-1]
for i in b:
    print(i, end = ' ')