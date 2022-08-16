from collections import *
from math import *
import re
s = input()
s = s.replace(';',',')
l = list(s.split(','))
a = []
b = []
for i in l:
    if i.isdigit() == True:
        if len(i)>1 and i[0] == '0':
            b.append(i)
        else:
            a.append(i)
    else:
        b.append(i)
if a == []:
    print("-")
else:
    print("\""+",".join(a)+"\"")
if b == []:
    print("-")
else:
    print("\""+",".join(b)+"\"")