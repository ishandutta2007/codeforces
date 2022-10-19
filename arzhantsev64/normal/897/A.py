n, m = list(map(int, input().split()))
s = input()
for i in range(m):
	l, r, c1, c2 = input().split()
	l = int(l)
	r = int(r)
	s = s[:l - 1] + s[l - 1:r].replace(c1, c2) + s[r:]
print(s)