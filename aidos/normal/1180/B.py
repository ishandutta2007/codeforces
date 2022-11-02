n = int(input())
a = list(map(int, input().split()))


for i in range(n):
    if a[i] >= 0:
        a[i] = -a[i] - 1
if n % 2 == 1:
    j = a.index(min(a))
    a[j] = -a[j]-1

for i in range(n):
    print(a[i])
#