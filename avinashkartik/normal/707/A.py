r,c = map(int,input().split())
l = []
for i in range(r):
    l.append(list(input().split()))
flag = 0
for i in range(r):
    for j in range(c):
        if(l[i][j] != 'B' and l[i][j] != 'W' and l[i][j] != 'G'):
            flag = 1
if(flag == 1):
    print("#Color")
else:
    print("#Black&White")