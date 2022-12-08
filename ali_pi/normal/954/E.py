rd = lambda: map(int, input().split())
n, t = rd()
a = list(rd())
b = list(rd())
x = [[b[i], a[i]] for i in range(n)]
x.sort()
tot, val = sum(a), 0
for i in range(n):
    val += (t - x[i][0]) * x[i][1]
if val:
    f = 2 * (val > 0) - 1
    for i in range(n)[::f]:
        if f * (val - x[i][1] * (t - x[i][0])) <= 0:
            tot -= val / (t - x[i][0])
            break
        tot -= x[i][1]
        val -= (t - x[i][0]) * x[i][1]
print(tot)