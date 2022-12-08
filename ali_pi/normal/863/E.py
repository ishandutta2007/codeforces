n = input()
a = [(-1,-1,0)]
for i in range(n):
    tl,tr = (map(int, raw_input().split()))
    a.append((tl,tr,i+1))
a.append((1000000001,1000000001,n+1))
a.sort()
for i in range(1,n+1):
    t = a[i]
    tp = a[i-1]
    tn = a[i+1]
    if (t[1]<=tp[1]) or (t[0]>=tn[0] and t[1]<=tn[1]) or (tp[1]+1>=tn[0] and t[1]<=tn[1]):
        print (t[2])
        break
else:
    print (-1)