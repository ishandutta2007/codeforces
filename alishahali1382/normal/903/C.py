n=int(input())
A=list(map(int,input().split()))
dic=dict()
for i in A:
    dic[i]=0
for i in A:
    dic[i]+=1
X=[]
for i in dic:
    X.append(dic[i])
print(max(X))