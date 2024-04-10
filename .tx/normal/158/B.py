import sys

inp = sys.stdin

n = int(inp.readline())
a = list(map(int, inp.readline().split()))
c = [0] * 5
for i in a:
	c[i] += 1

ans = c[4]
x = min(c[3], c[1])
c[3] -= x
c[1] -= x
ans += x
ans += c[3]
ans += c[2] // 2
c[2] %= 2
if c[2] == 1:
	c[1] = max(0, c[1] - 2)
	ans += 1
ans += (c[1] + 3) // 4
print(ans)