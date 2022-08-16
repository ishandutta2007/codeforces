t = int(input())
for i in range(t):
	x = input()
	y = input()
	x = x[::-1]
	y = y[::-1]
	for i in range(0,len(y)) :
		if y[i] is '1':
			index = i
			break
	#print(y,index)		
	for i in range(index,len(x)):
		if x[i] is '1':
			index1 = i
			break
	#print(x,index1)
	print(index1 - index)