n = int(input())
l = list(input())
#print(l)
s = 0
for i in range(n):
	#print(int(l[i]))
	if(int(l[i])%2 == 0):
		s += i+1
print(s)