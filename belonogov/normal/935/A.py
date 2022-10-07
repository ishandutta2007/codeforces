# a = ((a // b) * b) + (a % b)


n=int(input())
qwe=0
i=1
while i<n:
  r=n-i
  if r % i == 0:
    qwe=qwe+1
    i=i+1
  else :   
    i=i+1

print(qwe)