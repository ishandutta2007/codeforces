n, m = map(int, input().split())
a = [10 * 100, 1]
for i in range(n):
    x = list(map(int, input().split()))
    if x[0]/x[1] < a[0]/a[1]:
        a = x
print(a[0] * m/a[1])