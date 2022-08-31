n = input()
b = int(n,2)
for i in range(55):
	s = pow(4,i)
	if(s >= b):
		break
print(i)