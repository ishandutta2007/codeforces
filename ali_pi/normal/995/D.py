from fractions import *
from math import *
from itertools import *
from fractions import*
import string
import copy
import random
import bisect
from decimal import *
from collections import deque
def id_generator(size=20, chars=string.digits):
    return ''.join(random.choice(chars) for _ in range(size))
def mp():
    return map(int,str(raw_input()).split())
n,r=mp()
l=list(mp())
x=pow(2,n)
s=sum(l)
print(s/float(x))
for i in range(r):
	a,b=mp()
	s=s-l[a]
	s+=b
	l[a]=b
	print(s/float(x))