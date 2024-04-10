n = int(input())
a = list(map(int, input().split()))
d = dict()
for i in a:
    d[i] = d.get(i, 0) + 1
b = [2**i for i in range(31)]
ans = 0
for i in a:
    d[i] -= 1
    ok = 0
    for j in b:
        if d.get(j - i, 0) > 0:
            ok = 1
    d[i] += 1
    ans += ok
print(n - ans)