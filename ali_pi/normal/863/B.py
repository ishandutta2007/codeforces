n=2*input()
w=sorted(map(int,raw_input().split()))
r=10000
for i in range(n):
    for j in range(i):
        u=w[:j]+w[j+1:i]+w[i+1:]
        r=min(r,sum(u[i+1]-u[i] for i in range(0,n-3,2)) )
print(r)