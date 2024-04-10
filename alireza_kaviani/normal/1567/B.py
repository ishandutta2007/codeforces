MAXN = int(3e5 + 20)
xr = [0] * MAXN
for i in range(1 , MAXN):
    xr[i] = (xr[i - 1] ^ i)
q = int(input())
for _ in range(q):
    x , y = map(int , input().split())
    y ^= xr[x - 1]
    if(y == 0):
        print(x)
    elif(y == x):
        print(x + 2)
    else:
        print(x + 1)