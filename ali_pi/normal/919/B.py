def y(x):
	t=0
	while x:
		t=t+x%10
		x=x//10
	return t
n=input()
z=19
while n>1:
	z=z+9
	if y(z)==10:
		n=n-1
print (z)