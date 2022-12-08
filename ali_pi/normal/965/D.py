n, k, s, mn = map(int, raw_input().split() + [0, 10000000000])
a = list(map(int, raw_input().split()))
for i in range(0, n - 1):
    if i < k:
        s += a[i]
    else:
        mn = min(mn, s)
        s += a[i] - a[i - k]
print min(mn, s)