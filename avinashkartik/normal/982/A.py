n = int(input())
s = input()
s = '0'+s+'0'
f = 1
for i in range(1,n+1):
	if(s[i] == '0'):
		if s[i-1] == '0' and s[i+1] == '0':
			f = 0
	else:
		if s[i-1] == '1' or s[i+1] == '1':
			f = 0
if(f == 0):
	print("No")
else:
	print("Yes")