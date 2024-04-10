f,s=raw_input().split()
l=f[0]
for c in f[1:]:
	if c>=s[0]:break
	l+=c
print(l+s[0])