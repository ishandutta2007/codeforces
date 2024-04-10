n=int(raw_input())
a=list(map(int, raw_input().split()))
b=[0]*1001
for i in range(n):
    b[a[i]]+=1
ma=0    
for i in range(1001):
    if b[i]>ma:
        ma=b[i]
if ma-1<=n-ma:
    print('YES')
else:
    print('NO')