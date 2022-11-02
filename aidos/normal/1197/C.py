n, k = map(int, input().split())
a = list(map(int, input().split()))
c = [0] + sorted([-a[i] + a[i-1] for i in range(1, n)])
s = a[n-1] - a[0]
print(s + sum(c[:k]))