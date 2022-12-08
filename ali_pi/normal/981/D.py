n,k=map(int,raw_input().split())
book=map(int,raw_input().split())
spe=[0]
for b in book:
    spe.append(spe[-1]+b)

lock=0
for pos in range(60,-1,-1):
    trial=(1<<pos)+lock
    dp=[[False for i in range(n)] for j in range(k)]
    rs=0
    for i in range(n):
        rs+=book[i]
        if (rs&trial)==trial:
            dp[0][i]=True

    for shelf in range(1,k):
        rs=0
        for i in range(shelf,n-k+shelf+1):
            for cut in range(i):
                if not dp[shelf-1][cut]:
                    continue
                sm=spe[i+1]-spe[cut+1]
                if (sm&trial)==trial:
                    dp[shelf][i]=True

    if dp[-1][-1]:
        lock=trial
print (lock)