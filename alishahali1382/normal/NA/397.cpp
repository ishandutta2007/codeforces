n,k=map(int,input().split())
L=list(map(int,input().split()))
s=list(set(L))
j=0
dic=dict()
for i in L:
    j+=1
    dic[i]=j
if len(s)<k:
    print("NO")
else:
    print("YES")
    for i in s[:k]:
        print(dic[i],end=" ")
    print()