import sys

s = raw_input()
n = len(s)
f = [0] * (n + 1)
for i in range(1, n):
    f[i] = f[i - 1]
    if s[i] == '0':
        f[i] += 1
m = n
x = n
ans = 0
for i in reversed(range(n)):
    while i < m - i or i == m - i and s[:i] < s[i:m]:
        if x == m:
            print ans + 1
            sys.exit(0)
        ans += m - x - (f[m - 1] - f[x - 1])
        m = x
    if s[i] != '0':
        x = i