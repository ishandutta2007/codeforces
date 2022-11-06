import sys

fin = sys.stdin
fout = sys.stdout

a = list(map(int, fin.readline().strip().split()))
a.sort()
ans = 0
t = min(a[0], (a[2] - a[1]) // 2)
ans += t
a[0] -= t
a[2] -= 2 * t
ans += a[0]
a[1] -= a[0]
a[2] -= a[0]
t = min(a[1], a[2] - a[1])
ans += t
a[1] -= t
a[2] -= 2 * t
t = a[1] // 3 * 2
ans += t
a[1] -= t // 2 * 3
a[2] -= t // 2 * 3
if a[1] > 0 and a[1] + a[2] >= 3:
    ans += 1
print(str(ans), file=fout)