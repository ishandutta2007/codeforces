n,m,k=map(int,input().split())
L=[]
for i in range(n):
    L.append(list(input()))
st=(-1,-1)
emp=-1
for i in range(n):
    for j in range(m):
        if L[i][j]==".":
            st=i,j
            emp+=1
#print(emp)
levels=[[st]]
L[st[0]][st[1]]="Y"
while emp!=0 and k!=0:
    X=[]
    for i,j in levels[-1]:
        if i!=0:
            if L[i-1][j]==".":
                L[i-1][j]="Y"
                X.append((i-1,j))
                #print((i,j),(i-1,j))
                emp-=1
        if i!=n-1:
            if L[i+1][j]==".":
                L[i+1][j]="Y"
                X.append((i+1,j))
                #print((i,j),(i+1,j))
                emp-=1
        if j!=0:
            if L[i][j-1]==".":
                L[i][j-1]="Y"
                X.append((i,j-1))
                #print((i,j),(i,j-1))
                emp-=1
        if j!=m-1:
            if L[i][j+1]==".":
                L[i][j+1]="Y"
                X.append((i,j+1))
                #print((i,j),(i,j+1))
                emp-=1
    levels.append(X)

for i in range(n):
    for j in range(m):
        if L[i][j]=="Y":
            L[i][j]="."

X=[]
while k!=0:
    if X==[]:
        X=levels.pop()
    i,j=X.pop()
    L[i][j]="X"
    k-=1

for i in range(n):
    print("".join(L[i]))