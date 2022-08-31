from math import *
from collections import *
n,m = map(int,input().split())
flag = 0
a = []
for i in range(n):
    a.append(list(input()))
    for i in range(m):
        if(a[-1][i]) == '.':
            a[-1][i] = 'D'
for i in range(n):
    for j in range(m):
        if(a[i][j] == 'S'):
            if i > 0:
                if(a[i-1][j] == 'W'):
                    flag = 1
            if j > 0:
                if(a[i][j-1] == 'W'):
                    flag = 1
            if i < n-1:
                if(a[i+1][j] == 'W'):
                    flag = 1
            if j < m-1:
                if(a[i][j+1] == 'W'):
                    flag = 1

if flag == 1:
    print("No")
else:
    print("Yes")
    for i in a:
        print("".join(i))