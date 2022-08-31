a = "qwertyuiop"
b = "asdfghjkl;"
c = "zxcvbnm,./"
mv = input()
s = input()
ans = ""
if(mv == 'R'):
	j = -1
else:
	j = +1
for i in s:
	if(a.find(i) != -1):
		ans += a[a.index(i)+j]
	if(b.find(i) != -1):
		ans += b[b.index(i)+j]
	if(c.find(i) != -1):
		ans += c[c.index(i)+j]
print(ans)