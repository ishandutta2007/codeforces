from collections import *
from math import *
s = input()
e = input()
s = int(s[:2])*60+int(s[3:])
e = int(e[:2])*60+int(e[3:])
t = (s+e)//2
h = str(t//60)
m = str(t%60)
if(len(h) == 1):
	h = '0'+str(h)
if(len(m) == 1):
	m = '0'+str(m)
print(h+":"+m)