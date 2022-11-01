a = [list(map(int,raw_input().split()))for i in range(3)]
x = (a[1][0]+a[1][2]+a[2][0]+a[2][1]-a[0][1]-a[0][2])//2
a[0][0],a[1][1],a[2][2]=x,x+a[0][1]+a[0][2]-a[1][0]-a[1][2],x+a[0][1]+a[0][2]-a[2][0]-a[2][1]
for i in range(3):
    s=''
    for j in range(3):
        s+=str(a[i][j])+' '
    print(s)