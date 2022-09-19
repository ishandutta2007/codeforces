n = int(input())
if n < 6:
    print(-1)
else:
    if n % 2 == 0:
        c = 2
        for i in range(n//2):
            print(1,c)
            c+=1
        for i in range(n//2-1):
            print(2,c)
            c+=1
    if n%2 == 1:
        c = 2
        for i in range(n//2):
            print(1,c)
            c+=1
        for i in range(n//2):
            print(2,c)
            c+=1
for i in range(2,n+1):print(1,i)

'''def bs(i,j,v):
    global w
    print(i,j)
    if i == j:return i
    va = (i+j)//2
    if i == j-1:return i
    if w[va] > v:return bs(i,va,v)
    elif w[va] == v:return va
    else:return bs(va+1,j,v)
n,k,m = map(int,input().split())
w = input().split()
#w = sorted(w)
c = list(map(int,input().split()))
mc = c[:]
for i in range(k):
    a = list(map(int,input().split()))
    m = c[a[1]-1]
    for j in a[1:]:
        m = min(m,c[j-1])
    for j in a[1:]:
        mc[j-1] = m
a = input().split()
t = 0
for i in a:
    t += mc[w.index(i)]
print(t)
        
'''