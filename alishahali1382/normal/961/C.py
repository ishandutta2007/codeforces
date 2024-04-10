n=int(input())
L=[]
for k in range(4):
    x=0
    for i in range(n):
        A=list(map(int,input()))
        for j in range(n):
            x+=A[j]^((i-j)%2)
    L.append([x,n**2-x])
    if k!=3:
        input()

out=4*n**2
for i in range(4):
    for j in range(i+1,4):
        p,q=list({0,1,2,3}-{i,j})
        out=min(out,L[i][0]+L[j][0]+L[p][1]+L[q][1])
print(out)