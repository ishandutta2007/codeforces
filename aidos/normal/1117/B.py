n, m, k = map(int, input().split())
a = sorted(map(int, input().split()))
ans = 0
x = m//(k+1)
print((a[n-1] * k + a[n-2]) * x + m % (k + 1) * a[n-1])