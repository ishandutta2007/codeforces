n = int(input())
a = input()
s = ('RGB', 'RBG', 'BRG', 'BGR', 'GBR', 'GRB')
d = []
for x in s:
    b = []
    cnt = 0
    for i in range(n):
        b.append(x[i % 3])
        if x[i % 3] != a[i]:
            cnt += 1
    d.append([cnt, ''.join(b)])
d = sorted(d)
print(d[0][0], d[0][1])