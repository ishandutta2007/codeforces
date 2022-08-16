from collections import *
from math import *
from sys import *
n = int(input())
l = list(map(int,input().split()))
l.sort()
for i in l:
    print(i,end = " ")