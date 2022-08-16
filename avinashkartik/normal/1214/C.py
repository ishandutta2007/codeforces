b = int(input())
g = input()
n = 0
m = 0
e = 0
for i in g:
	if(i == '('):
		n += 1
	elif(i == ')' and n == m):
		e += 1
	else:
		m += 1
if(e <= 1 and n == m+e):
	print("Yes")
else:
	print("No")