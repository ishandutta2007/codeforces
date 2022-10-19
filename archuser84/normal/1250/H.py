n = int(input())
a = input().split()
for i in range(n):
    a[i]=int(a[i])
a.sort()
print(a[int((n - 1) / 2)])