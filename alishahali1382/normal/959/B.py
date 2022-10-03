n,k,m=map(int,input().split())
L=input().split()
A=list(map(int,input().split()))
for i in range(k):
    inp=list(map(int,input().split()))
    X=[]
    ind=1
    for i in range(2,inp[0]+1):
        if A[inp[i]-1]<A[inp[ind]-1]:
            ind=i
    #print(ind)
    for i in range(1,inp[0]+1):
        A[inp[i]-1]=A[inp[ind]-1]
    #print(A)

dic=dict()
for i in range(n):
    dic[L[i]]=A[i]


mes=input().split()
out=0
for i in mes:
    out+=dic[i]
print(out)