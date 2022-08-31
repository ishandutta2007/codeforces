n,k = map(int,input().split())
a = []
b = []
for i in range(n):
    a.append(list(map(int,input().split())))
for i in range(n):
    b.append(list(map(int,input().split())))

flag = 0
for i in range(n):
    r = 0
    for j in range(k):
        if(a[i][j] != b[i][j]):
            r+=1
    if(r%2 == 1):
        flag = 1
        break
for i in range(k):
    c = 0
    for j in range(n):
        if(a[j][i] != b[j][i]):
            c+=1
    if(c%2 == 1):
        flag = 1
        break
if(flag == 1):
    print("No")
else:
    print("Yes")