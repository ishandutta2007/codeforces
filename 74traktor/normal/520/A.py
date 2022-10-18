n = int(input())
s = input()
isi = [0] * 26
for c in s:
	if c <= 'z' and c >= 'a':
		isi[ord(c) - ord('a')] = 1
	else:
		isi[ord(c) - ord('A')] = 1
f = True
for i in range(26):
	if isi[i] == 0:
		f = False
if f:
	print("YES")
else:
	print("NO")