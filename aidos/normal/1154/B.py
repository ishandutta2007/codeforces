n = int(input())
a = set(map(int, input().split()))
b = list(a)
ans = -1
for x in range(-200, 200):
    g = set()
    for t in b:
        if x == t:
            continue
        g.add(abs(x-t))
    if len(g) == 0:
        ans = 0
    elif len(g) == 1:
        d = list(g)[0]
        if ans == -1:
            ans = d
        else:
            ans = min(ans, d)
print(ans)