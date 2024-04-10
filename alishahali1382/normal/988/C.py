import sys
k=int(input())
L=[]
dic=dict()
flag=False
for i in range(k):
    L.append([int(input())])
    L[i].append(list(map(int,input().split())))
    s=sum(L[i][1])
    q=[]
    for j in range(L[i][0]):
        if flag:
            sys.exit()
        t=s-L[i][1][j]
        if t in dic:
            x,y=dic[t]
            print("YES")
            print(i+1,j+1)
            print(x,y)
            flag=True
        else:
            q.append((t,i+1,j+1))
    for a,b,c in q:
        dic[a]=(b,c)
print("NO")