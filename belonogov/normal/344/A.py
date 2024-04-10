n=int(input())
i=0
qwerty=0
p=input()
while n-1>i:
  s=input()
  if p[1]==s[0]:
    qwerty=qwerty+1
  p=s
  i=i+1
qwerty=qwerty+1
print (qwerty)