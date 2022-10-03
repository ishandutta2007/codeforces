n,k=map(int,input().split())
A=list(map(int,str(n)))
A.reverse()
p=0
for i in range(k):
    if A[p]==0:
        p+=1
    else:
        A[p]-=1
for i in range(len(A)-1,p-1,-1):
    print(A[i],end="")
print()