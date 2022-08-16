from math import *
n,x = map(int,input().split())
ch = [0 for i in range(int(pow(2,18)+1))]
count = 0
for i in range(int(pow(2,n))):
    if(ch[i] == 0):
        ch[i^x] = 1
        count += 1
prev = 0
print(count - 1)
for i in range(1,int(pow(2,n))):
    if(ch[i] == 0):
        print(prev^i,end = " ")
        prev = i
print()