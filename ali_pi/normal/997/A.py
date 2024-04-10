n, x, y = map(int,raw_input().split())
a = raw_input()
cnt = 0
prev = '1'
for ai in a:
  if prev == '1' and ai == '0': cnt += 1
  prev = ai
if cnt == 0:
  print(0)
else:
  print(min(x,y)*(cnt-1)+y)