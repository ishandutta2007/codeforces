y,p=map(int,input().split())
flag=True
for i in range(p,y,-1):
    #print(i)
    f=True
    for j in range(2,min(y,int(i**0.5))+1):
        if i%j==0:
            f=False
            break
    if f:
        print(i)
        flag=False
        break
if flag:
    print(-1)