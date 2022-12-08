R=lambda:map(int,raw_input().split())
n,k,x=R()
a=list(R())
print(sum(a[:n-k])+k*x)