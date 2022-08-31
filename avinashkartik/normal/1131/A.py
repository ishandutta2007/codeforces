a=list(map(int,input().split()))
c=a[1]*(a[0]+2) + a[3]*(a[2]+2)+(a[0]+2)*2- (a[0]*a[1]+a[2]*a[3])
print(c)