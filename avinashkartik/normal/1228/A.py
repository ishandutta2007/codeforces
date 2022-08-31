l,r = map(int,input().split())
for i in range(l,r+1):
    flag = 0
    a = [0 for j in range(10)]
    #print(a)
    t = i
    while(t > 0):
        s = int(t%10)
        #print(s)
        a[s] += 1
        t //= 10
    #print(a)
    for j in range(10):
        if(a[j] >= 2):
            flag = 1
            break
    if(flag == 0):
        print(i)
        break
else:
    print(-1)