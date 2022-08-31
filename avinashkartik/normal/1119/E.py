n = int(input())
l1 = list(map(int,input().split()))
i = 0
j = 0
ct2 = 0
while(i<n):
    ct2 += l1[i]//3
    l1[i] %= 3
    if(l1[i] >= 1):
        l1[i] -= 1
        while(j < n):
            if(l1[j] >= 2):
                #print(i,j)
                ct2 += 1
                l1[j] -= 2
                break
            else:
                j += 1
    else:
        i += 1
print(ct2)