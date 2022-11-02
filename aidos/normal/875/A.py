n = int(input())
a = []
for i in range(100, 0, -1):
    if n <= i:
        continue
    x = n - i
    if sum(map(int, list(str(x)))) == i:
        a.append(x)
print(len(a))
for i in a:
    print(i, end = ' ')