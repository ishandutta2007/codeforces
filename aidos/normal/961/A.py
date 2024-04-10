n, m = map(int, input().split())
a = [0] * n
b = list(map(int, input().split()))
for x in b:
    a[x-1] += 1
print(min(a))