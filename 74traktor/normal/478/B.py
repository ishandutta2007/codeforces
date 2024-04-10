n, m = map(int, input().split())
tmp = n // m
s = tmp + 1
kol_s = n % m
kol_tmp = m - kol_s
imin = tmp * (tmp - 1) // 2 * kol_tmp + s * (s - 1) // 2 * kol_s
imax = (n - m + 1) * (n - m) // 2
print(imin, imax)