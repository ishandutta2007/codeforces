k, p = list(map(int, input().split()))
c = 0
for i in range(1, k + 1):
	s = str(i)
	s_ = s[::-1]
	c += int(s + s_)
	c %= p
print(c)