n = int(input())
if(n < 3):
    print(-1)
elif(n%2 == 0):
    print((n//2)*(n//2)-1,(n//2)*(n//2)+1)
else:
    print((n*n-1)//2,(n*n+1)//2)