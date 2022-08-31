a = ['a','e','i','o','u']
s = input()
f = 0
for i in s:
	if(i not in a and f == 1):
		print("NO")
		break
	if(i in a or i == 'n'):
		f = 0
	else:
		f = 1
else:
	if(f == 0): print("YES")
	else: print("NO")