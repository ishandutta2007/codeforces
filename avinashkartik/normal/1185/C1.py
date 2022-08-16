n,m = map(int,input().split())
l = list(map(int,input().split()))
a = []
ans = []
for i in range(n):
    if a == []:
        a.append(l[i])
        ans.append(0)
    else:
        s = 0
        for j in range(i):
            s += a[j]
            if(s+l[i]>m):
                ans.append(i-j)
                break
        else:
            ans.append(0)
        for j in range(i):
            if l[i] < a[j]:
                a.insert(j,l[i])
                break
        else:
            a.append(l[i])
    #print(a)
for i in ans:
    print(i,end = " ")