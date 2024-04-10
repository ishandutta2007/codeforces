n=int(input())
L=list(map(int,input().split()))
s=sum(L)
x=0
for i in range(n):
    x+=L[i]
    if x>=s/2:
        print(i+1)
        break