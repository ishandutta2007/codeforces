t = input()
ar = map(int ,raw_input().split())
cc = 0
c = 0
cou = 0
tt = []
for i in ar:
	a = int(i**(0.5))
	if i == 0:
		cou +=1
	if a**2 == i:
		c += 1 
	else:
		cc+=1
		tt.append(min(abs((a+1)**2-i) , abs((i - a**2))))
	
tt.sort()
if c > t/2 :
	if cou <= t/2:
		print (c - t/2 )
	else :
		print (c - cou + 2*(cou-t/2))
elif c == t/2 :
		print (0)
else:
	print (sum(tt[:t/2 -c]))