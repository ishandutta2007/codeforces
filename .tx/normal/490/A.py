import sys

inp = sys.stdin

n = int(inp.readline())
a = list(map(int, inp.readline().split()))
c = [0] * 3
b = [[], [], []]
for i in range(n):
	c[a[i] - 1] += 1
	b[a[i] - 1] += [i + 1]

x = min(c[0], c[1], c[2])
print(x)
for i in range(x):
	print("{0} {1} {2}".format(b[0][i], b[1][i], b[2][i]))