n, k = map(int, input().split())
a = list(map(int, input().split()))
b = [n - n % x for x in a]
i = b.index(max(b))
print(i + 1, n//a[i])