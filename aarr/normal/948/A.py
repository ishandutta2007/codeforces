a=input()
a=a.split()
R=int(a[0])
C=int(a[1])
l=[]
for i in range(R):
    l.append([])
    a=input()
    for j in range(C):
        l[i].append(a[j])
q=0
for i in range(1,R):
    for j in range(1,C):
        if l[i][j]=='S' and (l[i][j-1]=='W' or l[i-1][j]=='W'):
            q=1
        if l[i][j]=='W' and (l[i][j-1]=='S' or l[i-1][j]=='S'):
            q=1
if len(l)>1:
    if (l[0][0]=='W' and l[1][0]=='S') or (l[0][0]=='S' and l[1][0]=='W'):
        q=1
if len(l[0])>1:
    if (l[0][0]=='W' and l[0][1]=='S') or (l[0][0]=='S' and l[0][1]=='W'):
        q=1
for j in range(1,C):
    if l[0][j]=='S' and l[0][j-1]=='W':
        q=1
    if l[0][j]=='W' and l[0][j-1]=='S':
        q=1
for j in range(1,R):
    if l[i][0]=='S' and l[i-1][0]=='W':
        q=1
    if l[i][0]=='W' and l[i-1][0]=='S':
        q=1
if q==1:
    print('No')
if q==0:
    print('Yes')
    for i in range(R):
        b=''
        for j in range(C):
            if l[i][j]=='.':
                b=b+'D'
            if l[i][j]=='W':
                b=b+'W'
            if l[i][j]=='S':
                b=b+'S'
        print(b)