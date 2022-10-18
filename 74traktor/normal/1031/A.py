w, h, k = map(int, input().split())
s = 0

for i in range(k):
	s += (2 * w + 2 * h - 4)
	w -= 4
	h -= 4
print(s)