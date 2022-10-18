a, b, c, d = map(int, input().split())
t = [a, b, c]
t.sort()
a = t[0]
b = t[1]
c = t[2]
ans1 = 0
if a + d > b:
	ans1 += (a + d) - b
if max(a + d, b) + d > c:
	ans1 += (max(a + d, b) + d - c)
ans2 = 0
if a + d > b:
	ans2 += (a + d - b)
if b + d > c:
	ans2 += (b + d - c)
ans3 = 0
if c - d < b:
	ans3 += (b - c + d)
if min(c - d, b) - d < a:
	ans3 += (a + d - min(c - d, b))
print(min(ans1, ans2, ans3))