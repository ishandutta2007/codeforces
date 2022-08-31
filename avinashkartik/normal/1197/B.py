n = int(input())
l = list(map(int,input().split()))
m = max(l)
ind = l.index(m)
b = l[:ind]
c = l[ind:]
if(sorted(b) == b and sorted(c,reverse = True) == c):
    print("yes")
else:
    print("no")