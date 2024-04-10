n,m=map(int,input().split())
if n==1and m==1:print('YES\n1')
elif n==3and m==3:
    print('YES')
    print(6, 1, 8)
    print(7,5,3)
    print(2,9,4)
elif n<4and m<4:print('NO')
elif n==1 or m==1:
    t=max(n,m)
    a=[i for i in range(2,t+1,2)]
    a+=[i for i in range(1,t+1,2)]
    print('YES')
    for i in a:print(i,end="");print([' ','\n'][m==1],end='')
else:
    a=[]
    for j in range(n):
        a.append([int(i)+int(m*j) for i in range(1,m+1)])
    if n<=m:
        for j in range(1,m,2):
            t=a[0][j]
            for i in range(1,n):
                a[i-1][j]=a[i][j]
            a[n-1][j]=t
        for i in range(1,n,2):
            r,s=a[i][0],a[i][1]
            for j in range(2,m):
                a[i][j-2]=a[i][j]
            a[i][m-2],a[i][m-1]=r,s
    else:
        for j in range(1,m,2):
            r,s=a[0][j],a[1][j]
            for i in range(2,n):
                a[i-2][j]=a[i][j]
            a[n-2][j], a[n-1][j] = r, s
        for i in range(1,n,2):
            t=a[i][0]
            for j in range(1,m):
                a[i][j-1]=a[i][j]
            a[i][m-1]=t
    print('YES')
    for i in range(n):
        print(*a[i])