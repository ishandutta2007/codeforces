nm=map(int,raw_input().split())
N=nm[0]
M=nm[1]
X=[""]*N
a=[""]*N
for i in range(N):
	X[i]=raw_input();
for i in range(M):
	for j in range(N):
		a[j]+=X[j][i]
	flag=False
	for j in range(0,N-1):
		if a[j]>a[j+1]:
			flag=True
			break
	if flag:
		for j in range(N):
			a[j]=a[j][:-1]
print M-len(a[0])