n = input()
v = [x for x in range(max(1, n - 81), n) if x + sum(map(int, str(x))) == n]
print(len(v))
for vi in v:
    print(vi)