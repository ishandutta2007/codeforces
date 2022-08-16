from math import *
n,m = map(int,input().split())
l = []
for i in range(n):
    l.append(list(map(int,input().split())))
xor = 0
for i in range(n):
    xor = xor^l[i][0]

if(xor != 0):
    print("TAK")
    print("1 "*n)
else:
    ind = -1
    flag = 0
    for i in range(n):
        for j in range(1,m):
            if(l[i][j] != l[i][0]):
                ind = (i,j+1)
                flag = 1
                break
        if(flag == 1):
            break
    if(flag == 0):
        print("NIE")
    else:
        print("TAK")
        for i in range(n):
            if(i == ind[0]):
                print(ind[1],end = " ")
            else:
                print(1,end = " ")
        print()