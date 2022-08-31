from collections import *
a,b,x = list(map(int,input().split()))
oga = a
ogb = b
ans = ""
for i in range(x+1):
	if(i%2 == 0):
		if(oga < ogb):
			ans += '1'
			b -= 1
		else:
			ans += '0'
			a -= 1
	else:
		if(oga < ogb):
			ans += '0'
			a -= 1
		else:
			ans += '1'
			b -= 1
if(ans[0] == '0'):
	ans = (a+1)*'0' + (b+1)*'1' + ans[2:]
else:
	ans = (b+1)*'1' + (a+1)*'0' + ans[2:]
print(ans)