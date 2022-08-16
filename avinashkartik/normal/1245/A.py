from math import *
from collections import *
def gcd(a,b):  
    if (b == 0): 
         return a 
    return gcd(b, a%b) 

t = int(input())
for y in range(t):
    a,b = map(int,input().split())
    if(gcd(a,b) == 1): print("Finite")
    else: print("Infinite")