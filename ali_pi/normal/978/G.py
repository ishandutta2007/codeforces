a,b=map(int,raw_input().split())
d=[]
w=[0]*(a+1)
for i in range(b):
    x,y,z=map(int,raw_input().split())
    d.append([x,y,z,i+1])
    w[d[i][1]]=b+1
d.sort(key=lambda x:x[1])
s=0
for i in range(b):
    k=d[i][2]
    l=d[i][3]
    for j in range(d[i][0],d[i][1]):
        if(w[j]==0):
            w[j]=l
            k-=1
        if(k==0):
            break
    if(k!=0):
        s=1
        break
if(s==1):
    print -1
else:
    for i in range(1,a+1):
        print w[i],