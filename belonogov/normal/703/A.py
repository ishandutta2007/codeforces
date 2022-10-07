# s='2 3'
# print(s)
i=0
n=int(input())
m1=0
k1=0
while i<n:
  b=input().split()
  m = int(b[0])
  k = int(b[1])
# while n>i:  
  if m>k:
    m1=m1+1
  if m<k:  
    k1=k1+1
  i=i+1
if k1<m1:
  print('Mishka')
if k1>m1:
  print('Chris')
if k1==m1:
  print('Friendship is magic!^^')