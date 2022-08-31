from math import *
s = input()
n = len(s)
ans = o = e = 0
for i in range(n):
	if(s[i] == '4' or s[i] == '8' or s[i] == '0'):
		ans += 1
		if(i > 0 and int(s[i-1])%2 == 0):
			ans += i
	elif(s[i] == '2' or s[i] == '6'):
		if(i > 0 and int(s[i-1])%2 == 1):
			ans += i
print(ans)