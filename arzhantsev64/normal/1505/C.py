def n(c):
	return ord(c) - ord('A')

def work(s):
	for i in range(2, len(s)):
		if n(s[i]) != (n(s[i - 1]) + n(s[i - 2])) % 26:
			return False
	return True

s = input()
if work(s):
	print("YES")
else:
	print("NO")