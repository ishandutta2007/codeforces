n = int(input())
a = []
for i in range(n):
    a.append(list(input()))
for i in range(1,n-1):
    for j in range(1,n-1):
        if(a[i][j] == '.'):
            if a[i+1][j] == '.' and a[i-1][j] == '.' and a[i][j-1] == '.' and a[i][j+1] == '.' :
                a[i][j] = '#'
                a[i+1][j] = '#'
                a[i-1][j] = '#'
                a[i][j+1] = '#'
                a[i][j-1] = '#'
flag = 0
for i in range(n):
    for j in range(n):
        if a[i][j] == '.' :
            print("NO")
            flag = 1
            break
    if flag == 1:
        break
else:
    print("YES")