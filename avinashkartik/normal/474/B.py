N=[0 for i in range(1000001)]
n=int(input())
L=list(map(int,input().split()))
j=0

for i in L:
  N[i+j]=1
  j=i+j

P=[N[0]]
for i in range(1,1000001):
    P.append(P[i-1]+N[i])

k=int(input())
M=list(map(int,input().split()))
for i in range(k):
  print(P[M[i]-1]+1)