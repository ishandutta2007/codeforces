n=input()
l=[0 for i in range(n+1)]
lo=[]
lc=[]
for i in range(n):
	x,y=map(int,raw_input().strip().split())
	lo.append(x)
	lc.append(y)
lo.sort()
lc.sort()
i=1
j=0
count=1
st=lo[0]
ref=0
while(i<n and j<n):
	if (lo[i]<=lc[j]):
		if ref==0:
			l[count]=l[count]+lo[i]-st
		else:
			l[count]=l[count]+lo[i]-st-1
		ref=0
		count=count+1
		st=lo[i]
		i=i+1
	else:
		if (ref==0):
			l[count]=l[count]+lc[j]-st+1
		else:
			l[count]=l[count]+lc[j]-st
		count=count-1
		ref=1
		st=lc[j]
		j=j+1
while(j<n):
	if (ref==0):
		l[count]=l[count]+lc[j]-st+1
	else:
		l[count]=l[count]+lc[j]-st
	count=count-1
	ref=1
	st=lc[j]
	j=j+1
print (" ".join(map(str,l[1:])))