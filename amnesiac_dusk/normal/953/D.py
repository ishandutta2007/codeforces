a=[]
for i in range(0,6):
    a.append(input())
b=[[3,3,4,4,3,3],[3,3,4,4,3,3],[2,2,3,3,2,2],[2,2,3,3,2,2],[1,1,2,2,1,1],[1,1,2,2,1,1]]
for i in range(0,6):
    if(a[i][0]=='*'):
        b[i][0]=0
    if(a[i][1]=='*'):
        b[i][1]=0
    if(a[i][3]=='*'):
        b[i][2]=0
    if(a[i][4]=='*'):
        b[i][3]=0
    if(a[i][6]=='*'):
        b[i][4]=0
    if(a[i][7]=='*'):
        b[i][5]=0
c=0
d=0
e=0
for i in range(0,6):
    for j in range(0,6):
        if(b[i][j]>c):
            c=b[i][j]
            d=i
            e=j
if(e==2 or e==3):
    e=e+1
elif(e==4 or e==5):
    e=e+2
if(e!=7):
    a[d]=a[d][0:e]+'P'+a[d][e+1:8]
else:
    a[d]=a[d][0:e]+'P'
for i in range(0,6):
    print(a[i])