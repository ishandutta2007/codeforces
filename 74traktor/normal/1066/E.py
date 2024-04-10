n1, m1 = map(int, input().split())
s = input()
s1 = input()
mod = 998244353
k = [1] * (200001)
for i in range(1, 200001):
	k[i] = k[i - 1] * 2 % mod
b = [0] * m1
if s1[0] == '1':
	b[0] = 1
for i in range(1, m1):
	b[i] = b[i - 1] + (ord(s1[i]) - ord('0'))
res = 0
for i in range(n1):
	if s[i] == '1' and m1 - n1 + i >= 0 and m1 - n1 + i < len(b):
		res += k[n1 - i - 1] * b[m1 - n1 + i]
		res = res % mod
print(res % mod)