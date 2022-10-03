n=int(input())
L=[[0, i] for i in range(1,n+1)]
for i in range(n):
    L[i][0]=-sum(list(map(int,input().split())))
    
L.sort()
for i in range(n):
    if L[i][1]==1:
        print(i+1)
        break