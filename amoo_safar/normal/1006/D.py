'''n = int(input())
a = list(map(int,input().split()))
ps = [0]*n
ps[0] = a[0]
f = 1
for i in range(1,n):ps[i] = ps[i-1]+a[i]
ps2 = [0]*n
s = sum(a)
for i in range(n):ps2[i] = s - ps[i] + a[i]
print(ps2)
for i in range(n-2,0,-1):
    t = 0
    #print(ps[i])
    for j in range(n-1,i,-1):
        t+=a[j]
        if t == ps[i]:
            break
    if t == ps[i]:
        f = 0
        print(t)
        break
if f:print(0)
'''
n = int(input())
a = input()
b = input()
if(n%2 == 0):
    out = 0
    for i in range(n//2):
        t = [a[i],a[n-i-1],b[i],b[n-i-1]]
        f = set(t)
        #print(t)
        if ((t[2] != t[3]) and (len(f) == 4)) :out +=2
        elif ((t[2] != t[3]) and (len(f)==3) and (t[0] == t[1])):out += 2
        elif t[2] == t[3]:
            if t[0] != t[1]:out += 1
        else:
            if t[0] == t[2]:
                if t[1]!=t[3]:out+=1
            elif t[0] == t[3]:
                if t[1] != t[2]:out += 1
            elif t[1] == t[2]:
                if t[0]!=t[3]:out+=1
            elif t[1] == t[3]:
                if t[0] != t[2]:out += 1
    print(out)
else:
    out = 0
    for i in range(n//2):
        t = [a[i],a[n-i-1],b[i],b[n-i-1]]
        f = set(t)
        #print(t)

        if ((t[2] != t[3]) and (len(f) == 4)) :out +=2
        elif ((t[2] != t[3]) and (len(f)==3) and (t[0] == t[1])):out += 2
        elif t[2] == t[3]:
            if t[0] != t[1]:out += 1
        else:
            if t[0] == t[2]:
                if t[1]!=t[3]:out+=1
            elif t[0] == t[3]:
                if t[1] != t[2]:out += 1
            elif t[1] == t[2]:
                if t[0]!=t[3]:out+=1
            elif t[1] == t[3]:
                if t[0] != t[2]:out += 1
    if a[n//2] != b[n//2]:out += 1
    print(out)