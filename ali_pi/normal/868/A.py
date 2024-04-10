s=raw_input()
n=input()
a=[raw_input() for i in range(n)]
for x in a:
 for y in a:
  if s in x+y:
   print('YES')
   exit(0)
print('NO')