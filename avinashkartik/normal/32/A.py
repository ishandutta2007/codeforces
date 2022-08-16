n,d = map(int,input().split())
l = list(map(int,input().split()))
l.sort()
ct = 0
for i in range(n-1):
    for j in range(i+1,n):
        if(l[j] - l[i] <= d):
            ct += 2
print(ct)