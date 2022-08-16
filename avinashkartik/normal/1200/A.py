n = int(input())
s = input()
a = [0 for i in range(10)]
for x in s:
	if(x == 'L'):
		for i in range(10):
			if(a[i] == 0):
				a[i] = 1
				break
	elif(x == 'R'):
		for i in range(9,-1,-1):
			if(a[i] == 0):
				a[i] = 1
				break
	else:
		index = int(x)
		a[index] = 0
for i in range(10):
	print(a[i],end = '')