n,k=map(int,input().split())
L=[]
for i in range(n):
    L.append(input())

ps1=[[0]*(n+1) for i in range(n)]  #number of "#"
ps2=[[0]*n for i in range(n+1)]
for i in range(n):
    for j in range(n):
        ps1[i][j+1]=ps1[i][j]+int(L[i][j]=="#")
        ps2[i+1][j]=ps2[i][j]+int(L[i][j]=="#")

T=[[0]*n for i in range(n)]
for i in range(n):
    for j in range(n-k+1):
        if ps1[i][j+k]-ps1[i][j]==0:
            for x in range(k):
                T[i][j+x]+=1
for i in range(n-k+1):
    for j in range(n):
        if ps2[i+k][j]-ps2[i][j]==0:
            for x in range(k):
                T[i+x][j]+=1

ans1,ans2=0,0
for i in range(n):
    for j in range(n):
        if T[i][j]>T[ans1][ans2]:
            ans1,ans2=i,j
print(ans1+1,ans2+1)