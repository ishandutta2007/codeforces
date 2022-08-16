n = int(input())
a=[]
while(n > 0):
  if(n%7==0):
    n -= 7
    a.append('7')
  elif(n%4==0):
    n -= 4
    a.append('4')
  else:
    n -= 4
    a.append('4')
a.sort()
if(n < 0):
  print(-1)
else:
  print("".join(a))