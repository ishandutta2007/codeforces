X=input();
X=input();
(a, b, c, d, k) = (0, 0, 1, 1, 1);
l = len(X);
for i in range(1,l):
	if (X[i]==X[i-1]):
		if(c!=1):
			c+=1;
			b+=1;
		else:
			c+=1;
			b+=d;
	else:
		if(c!=1):
			b+=2-c-k
			d=c;
			c=1;
		else:
			b+=d-k;
			d=1
			c = 1;
		k=0;
	a+=b;
print(a);