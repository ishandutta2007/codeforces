R=lambda:map(int,input().split())
n=int(input())
a=sorted(R())
c=[0]*n
for i,(_,j) in enumerate(sorted(zip(R(),range(n)))):
  c[j]=a[-1-i]
print(' '.join(map(str,c)))