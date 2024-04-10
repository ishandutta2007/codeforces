n=int(input())
for i in range(n):
    c, sum=map(int,input().split())
    k=int(sum/c)
    r=sum - k*c
    print((c-r)*k*k + r*(k+1)*(k+1))