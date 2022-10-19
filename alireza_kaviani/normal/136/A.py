n=int(input())

a=[0]*n

t=list(map(int,input().split()))

for i in range(n):
    a[t[i]-1]=i+1
    
for i in a:
    print(i,end=' ')