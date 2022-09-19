h,m = map(int,input().split())
hu,d,c,n = map(int,input().split())
if h >= 20:
    if hu % n != 0:
        hu = hu + n-hu%n
    print((hu*4*c)/(5*n))
else:
    lhu = hu
    p = float('inf')
    if hu % n != 0:
        hu = hu + n-hu%n
    p = min(p,hu*c/n)
    #print(p)
    hu = lhu+((19-h)*60+(60-m))*d
    if hu % n != 0:
        hu = hu + n-hu%n
    p = min(p,(hu*c*4)/(5*n))
    print(p)