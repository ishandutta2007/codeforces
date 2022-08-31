s = input()
g,no,ans = 0,0,0
for i in range(len(s)):
	if(s[i] == 'M'):
		no = max(no-1,0)
	else:
		if(i != g):
			ans = max(ans,i-g+no)
			no += 1
		g += 1
print(ans)