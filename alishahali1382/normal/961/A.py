n,m=map(int,input().split())
inp=list(map(int,input().split()))
L=[0]*n
for i in inp:
    L[i-1]+=1
print(min(L))