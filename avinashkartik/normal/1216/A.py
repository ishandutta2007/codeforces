n = int(input())
s = list(input())
c = 0
for i in range(0,n-1,2):
	if(s[i] == s[i+1] and s[i] == 'a'):
		s[i] = 'b'
		c+=1
	elif(s[i] == s[i+1] and s[i] == 'b'):
		s[i] = 'a'
		c+=1
print(c)
print(''.join(s))