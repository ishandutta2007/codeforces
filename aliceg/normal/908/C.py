n, r = map(int, input().split())
x = list(map(int, input().split()))
y = [r] * n
for i in range(n):
    for j in range(i):
        if not (abs(x[i] - x[j]) > 2 * r):
            y[i] = max(y[i], (4 * r ** 2 - (x[i] - x[j]) ** 2) ** 0.5 + y[j])

for i in y:
    print(i, end=' ')