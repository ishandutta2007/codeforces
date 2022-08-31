n = int(input())
a = []
for i in range(n):
    a.append(list(map(int,input().split())))
k = int(input())
for y in range(k):
    u,v,d = map(int,input().split())
    u = u-1
    v = v-1
    a[u][v] = min(a[u][v],d)
    for i in range(n):
        for j in range(n):
            s = a[i][u] + a[u][v] + a[v][j]
            s2 = a[i][v] + a[u][v] + a[u][j]
            s1 = a[i][j]
            a[i][j] = min(s,s1,s2)
    sum1 = 0
    for i in range(n):
        sum1 += sum(a[i])
    print(sum1//2,end = " ")
print()