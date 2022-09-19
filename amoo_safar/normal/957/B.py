n,m = map(int,input().split())
a = []
f = 0
for i in range(n):a.append(input())
for i in range(n):
    for j in range(i+1,n):
        r1 = a[i]
        r2 = a[j]
        f1 = f2 = 0
        for k in range(m):
            if r1[k] != r2[k]:f1 = 1
            if (r1[k] == '#') and (r2[k]=='#'):f2 = 1
        if f1 == 1:
            if f2 == 1:
                f = 1
if f:print('No')
else:print('Yes')