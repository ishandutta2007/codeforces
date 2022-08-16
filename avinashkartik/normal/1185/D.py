n = int(input())
a = list(map(int,input().split()))
b = sorted(a)
d = dict()
for i in range(n-1):
    dif = b[i+1] - b[i]
    if dif in d:
        d[dif] += 1
    else:
        d[dif] = 1
key = -1
ind = 3000000000
flag = 0
#print(d)
for k,v in d.items():
    if d[k] >= n-3:
        flag = 1
        if(k>key):
            key = k
        
#print(key)
if(n <= 3):
    print(1)
elif(flag == 1):
    if(b[1] - b[0] != key and b[n-1] - b[n-2] == key and b[2] - b[1] == key):
            ind = b[0]
    elif(b[n-1] - b[n-2] != key and b[1] - b[0] == key and b[n-2] - b[n-3] == key):
            ind = b[n-1]
    elif(len(d) == 1):
            ind = b[0]
    else:
        for i in range(1,n-1):
            if((b[i] - b[i-1] != key and b[i+1] - b[i] != key) or (b[i-1] == b[i] and b[i]-b[i-1]!=key)):
                ind = b[i]
                flag = 0
                break

    #print(b[n-1] - b[n-2])

    #print(ind)
    #print(b,b.index(ind))
    if(flag == 1 or b[b.index(ind)+1] - b[b.index(ind)-1] == key) and ind != 3000000000:
        print(a.index(ind)+1)
    else:
        print(-1)
else:
    print(-1)