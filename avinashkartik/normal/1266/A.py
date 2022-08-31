t = int(input())
for y in range (t):
  s = input()
  o=e=z=0
  for i in s:
    if(int(i) % 2 == 0): e+=1
    if(i == '0'): z+=1
    o += int(i)
  if(o%3==0 and e>=2 and z>=1):
    print("red")
  else:
    print("cyan")