n = input()
a = [int(x) for x in raw_input().split()]

y = []
for s, t in zip(a, a[1:]):
    if abs(s - t) != 1 and s != t:
        y.append(abs(s - t))
y.append(1)
y = y[0]

for s, t in zip(a, a[1:]):
    if not(abs(s - t) == y or (abs(s - t) == 1 and min(s, t) % y != 0)):
        break
else:
    print("YES")
    print("{} {}".format(10**9, y))
    exit()

print("NO")