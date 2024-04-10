n, m = map(int, input().split())
d = dict()
a = map(int, input().split())
ans = []
for x in a:
    d[x] = d.get(x, 0) + 1
    if len(d) == n:
        for i in range(1, n + 1):
            d[i] -= 1
            if d[i] == 0:
                d.pop(i)
        ans.append('1')
    else:
        ans.append('0')
print(''.join(ans))