n = int(input())
s = input()
if(s.count(')') != s.count('(')):
	print(-1)
	exit(0)
ans = 0
ct = 0
st = -1
f = 0
for i in range(n):
	if(s[i] == '('): ct += 1
	else: ct -= 1
	if(ct == 0):
		if(f == -1): ans += i-st
		f = 0
		ct = 0
		st = i
	if(ct < 0):
		f = -1
print(ans)