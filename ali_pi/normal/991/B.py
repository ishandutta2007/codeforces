n=input()
a=list(map(int,raw_input().split()))
a.sort()
i=0
while sum(a)<4.5*n:
    a[i]=5
    i+=1
print(i)