n = int(input())
s = input()
for i in range(1, n + 1):
	if n % i == 0:
		pt = s[0:i]
		s = pt[::-1] + s[i:len(s)]
print(s)