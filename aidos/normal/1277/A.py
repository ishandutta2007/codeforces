t = int(input())
a = []
for i in range(1, 10):
    x = 0
    for j in range(9):
        x = x * 10 + i
        a.append(x)
a = sorted(a)
for _ in range(t):
    n = int(input())
    i = 0
    while i < len(a) and a[i] <= n:
        i += 1
    print(i)