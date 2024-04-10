n,m = map(int,input().split())
a = []
for i in range(n):
    a.append(list(input()))
t = 0
for i in range(n):
    for j in range(m):
        if a[i][j] == 'S':
            if (i > 0):
                if a[i-1][j] == 'W':
                    t = 1
                    break
                elif a[i-1][j] == '.':
                    a[i-1][j] = 'D'
            if (j < m-1):
                if a[i][j+1] == 'W':
                    t = 1
                    break
                elif a[i][j+1] == '.':
                    a[i][j+1] = 'D'
            if (i < n-1):
                if a[i+1][j] == 'W':
                    t = 1
                    break
                elif a[i+1][j] == '.':
                    a[i+1][j] = 'D'
            if (j > 0):
                if a[i][j-1] == 'W':
                    t = 1
                    break
                elif a[i][j-1] == '.':
                    a[i][j-1] = 'D'
if t == 1:print('No')
else:
    print('Yes')
    for i in a:
        for j in i:
            print(j,end ='')
        print()