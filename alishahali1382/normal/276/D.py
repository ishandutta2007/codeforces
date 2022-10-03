a,b=map(int,input().split())
s1=list(map(int,reversed(list(bin(a)[2:]))))
s2=list(map(int,reversed(list(bin(b)[2:]))))
s1+=[0]*(len(s2)-len(s1))
out=0
for i in range(len(s1)):
    if s1[i]^s2[i]:
        out=i+1

print(2**out-1)