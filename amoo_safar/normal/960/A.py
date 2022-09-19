s = input()
i = 0
while i < len(s):
    if s[i] == 'a':i+=1
    else:break
while i < len(s):
    if s[i] == 'b':i+=1
    else:break
while i < len(s):
    if s[i] == 'c':i+=1
    else:break
ac =s.count('a')
bc = s.count('b')
cc = s.count('c')
if ac > 0 and bc > 0 and cc > 0 and (cc in[ac,bc]) and (i == len(s)):print('YES')
else:print('NO')