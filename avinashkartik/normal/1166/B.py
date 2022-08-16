from math import *
n = int(input())
x = 0
y = 0
for i in range(int(sqrt(n))+1,0,-1):
    if(n%i == 0):
        x = i
        y = n//i
        break
if(x >= 5 and y >= 5):
    l = [['a' for i in range(y)] for i in range(x)]
    for i in range(x):
        for j in range(y):
            if((j-i+5)%5 == 0): continue
            elif((j-i+5)%5 == 1): l[i][j] = 'e'
            elif((j-i+5)%5 == 2): l[i][j] = 'i'
            elif((j-i+5)%5 == 3): l[i][j] = 'o'
            else: l[i][j] = 'u'
    #for i in l:
        #print(i)
    ans = ""
    for i in range(x):
        ans += "".join(l[i])
    print(ans)
else:
    print(-1)