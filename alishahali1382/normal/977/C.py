n,k=map(int,input().split())
A=list(map(int,input().split()))+[1000000001]
A.sort()
if k==0:
    if A[0]==1:
        print(-1)
    else:
        print(1)
else:
    if A[k]==A[k-1]:
        print(-1)
    else:
        print(A[k-1])