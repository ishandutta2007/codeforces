n, k = map(int, input().split())
cur = min(k-1+n-1, n-k+n-1)
print(cur + n + n + 1)