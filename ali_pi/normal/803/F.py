n=input()
L=list(map(int,raw_input().split(' ')))
D=[0]*101000
mod=10**9+7
itt=[0]*101000
p=[0]*100010
D[0]=1
for i in range(100010):
  D[i+1]=(D[i]*2)%mod
for i in range(n):
  itt[L[i]]+=1 
for i in range(1,100001):
  for j in range(i*2,100001,i):
    itt[i]+=itt[j]
  p[i]=(D[itt[i]]+mod-1)%mod
i=100000
while i>=1:
  for j in range(i*2,100001,i):
    p[i]-=p[j]
  p[i]=(p[i]%mod+mod)%mod
  i-=1
print(p[1])