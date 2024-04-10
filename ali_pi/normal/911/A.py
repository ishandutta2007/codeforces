n=input()
a=list(map(int,raw_input().split()))
m=min(a)
b=[i for i in range(n) if a[i]==m]
c=[b[i+1]-b[i] for i in range(0,len(b)-1)]
print(min(c))