s = input()
a = int(s)
n = len(s)
r = (a - (45 * n * 10 ** (n - 1) + 1) % a) % a
print(r + 1, 10 ** n + r)