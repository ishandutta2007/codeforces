n, m = map(int, raw_input().split())
aa = list(map(int, raw_input().split()))
res, q = sum(aa), n // m
acc = [[] for _ in range(m)]
for i in range(n):
    acc[aa[i] % m].append(i)
j = -m
for i, l in enumerate(acc):
    if len(l) > q:
        if j <= i - m:
            j = i - m + 1
        while len(l) > q:
            while len(acc[j]) >= q:
                j += 1
            aa[l.pop()] += j + m - i
            acc[j].append(0)
print(sum(aa) - res)
print(' '.join(map(str, aa)))