n,m=map(int,input().split())
if n>m:
    print(m+1)
    for i in range(m+1):
        print(n-i,i)
else:
    print(n+1)
    for i in range(n+1):
        print(i,m-i)