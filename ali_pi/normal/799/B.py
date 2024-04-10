n = input()
p = map(int, raw_input().split())
a = map(int, raw_input().split())
b = map(int, raw_input().split())
input()
c = map(int, raw_input().split())
t = sorted(zip(p, a, b), key=lambda x: x[0])
p = [None, 0, 0, 0]
r = []
for ci in c:
    i = p[ci]
    while i < n and (t[i] is None or ci not in (t[i][1:])):
        i += 1
    if i == n:
        r.append('-1')
    else:
        r.append(str(t[i][0]))
        t[i] = None
        i += 1
    p[ci] = i
print(' '.join(r))