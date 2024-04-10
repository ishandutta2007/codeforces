n = int(input())
m = int(input())
a = [0] * n
for i in range(n):
    a[i] = int(input())
a = sorted(a)
j = n-1
while m > 0:
    m -= a[j]
    j -= 1
print(n-j-1)