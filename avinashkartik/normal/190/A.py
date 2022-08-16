n,m = map(int,input().split())
if(n == 0 and m > 0):
    print("Impossible")
else:
    print(n+m-min(n,m),n+m-min(m,1))