L=int(input())
C=set("abcdefghijklmnopqrstuvwxyz")
shock=0
for i in range(L):
	x,y=raw_input().split()
	if len(C)==1 and (x != '.'):
		shock+=1
	else:
		if x == '!':
			C=C&set(y)
		else:
			C=C-set(y)
print(max(shock-1,0))