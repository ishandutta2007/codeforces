from math import *
t = int(input())
for y in range(t):
    for z in range(t):
        if((y+z)%2 == 0):
            ch = 'B'
        else:
            ch = 'W'
        print(ch,end = "")
    print()