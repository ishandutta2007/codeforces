R=lambda:map(int,raw_input().split())
n,k,l=R()
a=[abs(x-y)for x,y in zip(R(),R())]
for _ in[0]*(k+l):
 a.sort();a[-1]=abs(a[-1]-1)
print(sum(i*i for i in a))