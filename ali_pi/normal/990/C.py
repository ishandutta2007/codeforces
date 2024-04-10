from collections import defaultdict as d
a, b = d(int), d(int)
for _ in range(int(raw_input())):
    s, m = 0, 1e9
    for x in raw_input():
        s += 2 * (x == '(') - 1
        m = min(m, s)
    if s >= 0 and m >= 0:
        a[s] += 1
    if s <= 0 and m == s:
        b[-s] += 1
print(sum(a[x] * b[x] for x in a))