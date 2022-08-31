from collections import *
n = int(input())
l = list(map(int,input().split()))
i = -1
l.sort()
ct = 0
s = list(Counter(l).values())
flag = 0
m = Counter(l)
for k,v in m.items():
    if m[k] == 2:
        if k-1 in m:
            flag = 1 
s.sort()
#print(s)
if(s[-1] >= 3 or (len(s)>1 and s[-1] == s[-2] == 2) or (l.count(0)>1) or flag == 1):
    print("cslnb")
else:
    for j in range(n):
        if l[j] == i:
            continue
        else:
            i += 1
            ct += l[j]-i
    #print(ct)
    if ct%2 == 0:
        print("cslnb")
    else:
        print("sjfnb")