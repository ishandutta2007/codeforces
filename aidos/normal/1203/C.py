n = int(input())
a = list(map(int, input().split()))
z = a[0]
for x in a:
    while x % z != 0:
        x, z = z, x % z
ans = 0
for i in range(1, 10 ** 6+1):
    if z % i == 0:
        j = z//i
        if i < j:
            ans += 2
        if i == j:
            ans += 1
print(ans)