R=lambda:map(int,raw_input().split())
n,x=R()
print(['NO','YES'][sum(R())+n-1==x])