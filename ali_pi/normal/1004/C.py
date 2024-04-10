from bisect import*
n=input()
N=100001
l=[N]*N
r=[-1]*N
for i,x in enumerate(map(int,raw_input().split())):
 l[x]=min(l[x],i);r[x]=max(r[x],i)
l.sort()
print(sum(bisect_left(l,x)for x in r))