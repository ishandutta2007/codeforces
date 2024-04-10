n,m = map(int,input().split())
a =[]
for i in range(n):
    a.append(input())
f = 1
for i in range(n):
    for j in range(m):
        c = 0
        if a[i][j] == '.':t=0
        elif a[i][j] == '*':t=-1
        else:t=int(a[i][j])
        if t!= -1:
            for k1 in range(-1,2):
                for k2 in range(-1,2):
                    if (0 <= i+k1 < n)and(0 <= j+k2 <m):
                        if a[i+k1][j+k2] == '*':c+=1
            if c!=t:
                f = 0
                break

if f:print('YES')
else:print('NO')