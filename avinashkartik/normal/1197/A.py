t = int(input())
for y in range(t):
    n = int(input())
    l = list(map(int,input().split()))
    l.sort()
    p = 0
    for i in range(n-2,0,-1):
        if(l[n-2] > i):
            p = i
            break
    print(p)