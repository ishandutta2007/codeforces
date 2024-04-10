n = int(input())
a = []
for i in range(n):
    a.append(list(map(int,input().split()))+[i+1])
a.sort(key = lambda e:e[0])
f = 0
for i in range(n-1):
    if a[i][0] == a[i+1][0]:
        if a[i][1] >= a[i+1][1]:
            print(a[i+1][2],a[i][2])
        else:print(a[i][2],a[i+1][2])
        f =1
        break
    if a[i][1] >= a[i+1][1]:
        f = 1
        print(a[i+1][2],a[i][2])
        break
if f == 0:print(-1,-1)