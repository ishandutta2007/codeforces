n,d = map(int,input().split())
a = list(map(int,input().split()))
max = 0
for i in range(n):
    l = a[:i+1]
    #print(len(l))
    l.sort(reverse = True)
    s = 0
    for j in range(0,i+1,2):
        s += l[j]
    if(s <= d):
        if(i+1 > max):
            max = i+1
    else:
        break
print(max)