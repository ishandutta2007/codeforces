n = int(input())
a = list(map(int, input().split()))
x = min(a)
d = x//n
for i in range(n):
    a[i] = a[i] - d * n
i = 0
z = 0
while a[i] > z:
    z += 1
    i=(i+1) % n
print(i+1)