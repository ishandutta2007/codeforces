n = int(input())
a = list(map(int, input().split()))
print(n+1)
x = 0
for i in range(n-1, -1, -1):
    z = (i-a[i]-x) % n
    print(1, i + 1, z)
    x += z
print(2, n, n)