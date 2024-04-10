n = input()
a = list(map(int, raw_input().split()))
s = a[0] % 998244353
y = a[0]
for x in a[1:]:
	s = s * 2 + y + x
	y = y * 2 + x
	s %= 998244353
	y %= 998244353
print(s)