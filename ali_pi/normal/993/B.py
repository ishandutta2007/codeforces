n, m = map(int, raw_input().split())
p1 = list(map(int,raw_input().split()))
p2 = list(map(int,raw_input().split()))
cand = set()
cc = [set() for i in range(n)]
dd = [set() for i in range(m)]
for i in range(n):
    for j in range(m):
        a, b = p1[2 * i], p1[2 * i + 1]
        c, d = p2[2 * j], p2[2 * j + 1]
        if a not in (c, d) and b not in (c, d):
            continue
        if a in (c, d) and b in (c, d):
            continue
        if a in (c, d):
            kandidat = a
        else:
            kandidat = b
        cand.add(kandidat)
        cc[i].add(kandidat)
        dd[j].add(kandidat)
if len(cand) == 1:
    print(cand.pop())
elif max(len(cc[i]) for i in range(n)) <= 1 and\
        max(len(dd[i]) for i in range(m)) <= 1:
    print(0)
else:
    print(-1)