n = int(input())
a = list(map(int,input().split()))
b = []
for i in range(n):
	if(a[i] == 1):
		b.append(-1)
	else:
		b.append(1)
meh = 0
msf = -1
for i in range(n):
	meh = max(meh+b[i],b[i])
	msf = max(msf,meh)
print(msf+sum(a))