n=int(input())
A=list(map(int,input().split()))
A.reverse()
L=[0]*1001
out=[]
for i in range(n):
    if not L[A[i]]:
        out.append(A[i])
        L[A[i]]=1
out.reverse()
print(len(out))
for i in out:
    print(i,end=" ")