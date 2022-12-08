a=input()
b=raw_input().split()
for i in range (a):
	if int(b[i])%2==0:
		print int(b[i])-1,
	else:
		print b[i],