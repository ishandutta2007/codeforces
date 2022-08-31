n = int(input())
a = list(map(int,input().split()))
max = 0
i = 0
while(i<n):
    ct1 = 0
    for j in range(i,n):
        if(a[j] != a[i]):
            break
        ct1 += 1
    ct2 = 0
    for j in range(i+ct1,n):
        if(a[j] == a[i]):
            break
        ct2 += 1
    #print(ct1,ct2)
    if(min(ct1,ct2) > max):
        max = min(ct1,ct2)
    i += ct1
print(2*max)