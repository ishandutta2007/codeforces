from math import *
x1,y1,r1 = map(int,input().split())
x2,y2,r2 = map(int,input().split())
dist = sqrt((x1-x2)**2+(y1-y2)**2)
dist -= r1+r2
#print(dist)
if dist>=0: print(dist/2)
else:
    dist += r1+r2
    x = (max(r1,r2)-dist-min(r1,r2))/2
    print(max(x,0))