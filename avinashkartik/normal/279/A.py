from math import *
from collections import *

x,y = map(int,input().split())
if(x>=y and (x+y)>1):print(4*x-3)
elif(x<y and y>=-x):print(4*y-2)
elif(y<-x and y>=x):print(4*(-x)-1)
else:print(4*(-y))