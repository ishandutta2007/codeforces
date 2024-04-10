a,b = map(int,raw_input().split(' '))
s = raw_input()
s1 = sorted(set(s))

if b>a:
 print(s+s1[0]*(b-a))
else:
 i = b-1
 while s[i]>=s1[-1] and i>-1:
  i -= 1
 d = s1.index(s[i])
 print(s[:i]+s1[d+1]+s1[0]*(b-i-1))