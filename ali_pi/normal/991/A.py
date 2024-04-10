a,b,c,n=map(int,raw_input().split())
n-=a+b-c
print((-1,n)[n>0and a>=c<=b])