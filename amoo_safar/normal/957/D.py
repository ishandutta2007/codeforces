n = int(input())
a = list(map(int,input().split()))
ne = n*[0]
ned = 1
for i in range(n-1,-1,-1):
    if a[i]+1 > ned:
        ned = a[i]+1
    ne[i] = ned
    ned -= 1
#print(ne)
ne.append(0) 
le = 1
o = 0
for i in range(n):
    o += le-a[i]-1
    #print(le)
    if le < ne[i+1]:
        le += 1
    #o = le-a[i]-1
    
print(o)