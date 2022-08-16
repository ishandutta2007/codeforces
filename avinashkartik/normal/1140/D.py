from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n = int(input())
ans = n*(n*n - 1)//3 - 2
print(ans)