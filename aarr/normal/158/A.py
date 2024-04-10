b=0
nk=input()
nk=nk.split()
n=int(nk[0])
k=int(nk[1])
l=input()
l=l.split()
for i in range(n):
    l[i]=int(l[i])
for i in range(n):
    if l[i]>=l[k-1] and l[i]>0:
        b=b+1
print(b)