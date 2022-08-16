if(1):
    n,m,r = map(int,input().split())
    a = list(map(int,input().split()))
    b = list(map(int,input(). split()))
    u = min(a)
    v = max(b)
    if(v > u):
        s = r//u
        r = r%u
        r += s*v
    print(r)