s = input()
a, b, c, d, e = input().split()
f = False
t = [a, b, c, d, e]
for x in t:
	if s[0] == x[0] or s[1] == x[1]:
		f = True
if f:
	print("YES")
else:
	print("NO")