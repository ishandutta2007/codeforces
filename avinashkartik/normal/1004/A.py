n,d = map(int,input().split())
a = list(map(int,input().split()))
if(n == 1):
    print(2)
else:
    ct = 0
    inv = 0
    for i in range(n):
        if(i != 0):
            if(a[i] - d >= a[i-1] + d):
                #print(a[i] - d)
                ct += 1
            if(a[i] - d == a[i-1] + d):
                inv += 1
        if(i != n-1):
            if(a[i] + d <= a[i+1] - d):
                #print(a[i] + d)
                ct += 1
            if(a[i] + d == a[i+1] - d):
                inv += 1
    print(ct - inv//2 + 2)