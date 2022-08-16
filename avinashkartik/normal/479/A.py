from math import *
from collections import *
a = int(input())
b = int(input())
c = int(input())
b1 = b
if(a == 1 or b == 1):
    b += a
else:
    b *= a
if(c == 1):
    b += c
else:
    b *= c
if(c == 1 or b1 == 1):
    b1 += c
else:
    b1 *= c
if(a == 1):
    b1 += a
else:
    b1 *= a
print(max(b,b1))