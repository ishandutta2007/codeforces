R=lambda:map(int,raw_input().split())
n,k=R()
a=list(R())
print(sum(min(max(a[:i+1]),max(a[i:]))<=k for i in range(n)))