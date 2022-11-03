n = int(input())
a = list(map(int, input().split()))
b = 500000.5
if a[0] > b:
    print(10 ** 6 - a[0])
    exit(0)
if a[n - 1] < b:
    print(a[n - 1] - 1)
    exit(0)
i = 0
while i < n - 1 and not (a[i] < b < a[i + 1]):
    i += 1
print(max(a[i] - 1, 10 ** 6 - a[i + 1]))