n = int(input())
d = {chr(i): 1 for i in range(97, 123)}
flag = False
ans = 0
for i in range(n):
    t, w = input().split()
    if flag and (t == '!' or (t == '?' and i != n - 1)):
        ans += 1
        continue
    if t =='?' and i != n - 1:
        d[w] = 0
    elif t == '.':
        for j in w:
            d[j] = 0
    elif t == '!':
        s = set([chr(i) for i in range(97, 123)])
        for j in w:
            if j in s:
                s.remove(j)
        for j in s:
            d[j] = 0
    k = 0
    for j in range(97, 123):
        k += d[chr(j)]
    if k == 1:
        flag = True
print(ans)