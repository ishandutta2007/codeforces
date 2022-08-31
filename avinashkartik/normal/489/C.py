from math import *
from collections import *

n,m = map(int,input().split())
m1 = m
s = []
s1 = []
if(n == 1 and m == 0):
    print("0 0")
elif(m == 0 or 9*n < m):
    print("-1 -1")
else:
    for i in range(n):
        if(m1 >= 9):
            s.append('9')
            m1 -= 9
        else:
            s.append(str(m1))
            m1 = 0
    for i in range(n):
        if(i == 0):
            if((n-i-1)*9 > m-1):
                s1.append('1')
                m -= 1
            else:
                s1.append(str(m-(n-i-1)*9))
                m -= m-(n-i-1)*9
        else:
            if((n-i-1)*9 > m):
                s1.append('0')
            else:
                s1.append(str(m-(n-i-1)*9))
                m -= m-(n-i-1)*9
    print("".join(s1),"".join(s))