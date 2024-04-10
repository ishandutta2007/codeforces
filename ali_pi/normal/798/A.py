n=raw_input()
d=sum([i!=j for i,j in zip(n,n[::-1])])
print(['NO','YES'][d==2 or (d==0 and len(n)%2)])