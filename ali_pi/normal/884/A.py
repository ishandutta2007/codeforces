n,t=list(map(int,raw_input().split()))
a=raw_input().split()
i=0
while t>0:
    t-=(86400-int(a[i]))
    i+=1
print(i)