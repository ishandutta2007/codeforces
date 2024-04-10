a,b = map(int,raw_input().split())
s = raw_input()

i = 0;
j = 0;

while i < a - 1 and j < a:
  if s[i] == '1':
    i += b
    j += 1
  else :
    i -= 1

if j >= a:print(-1)
else : print(j)