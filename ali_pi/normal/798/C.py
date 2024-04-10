s, i, n = 0, 0, int(raw_input())
t = list(map(int, raw_input().split())) + [0]
while i < n:
    if t[i] % 2:
        i += 1
        s += 2 - t[i] % 2
    i += 1
b = t[0]
for a in t:
    while a: a, b = b % a, a
    if b == 1: break
print 'YES', 0 if b > 1 else s