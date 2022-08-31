from collections import *
from math import *
from sys import *
n,m = map(int,input().split())
if(m <= ceil(n/2)):
    print(2*m-1)
else:
    print(2*(m-ceil(n/2)))