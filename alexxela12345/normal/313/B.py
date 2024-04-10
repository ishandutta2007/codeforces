a = input()
w=[0]
z,j =0,1
for i in range(1,len(a)):
	if a[i]==a[i-1]:
		z+=1
	w.append(z)
for i in range(int(input())):
	a,b = map(int,input().split())
	print(w[b-1]-w[a-1])