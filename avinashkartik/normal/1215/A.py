a1 = int(input())
a2 = int(input())
k1 = int(input())
k2 = int(input())
n = int(input())
min2 = (k1-1)*a1 + (k2-1)*a2
if(min2 < n):
    min1 = n - min2
else:
    min1 = 0

if(k1 < k2):
    K1 = k1
    A1 = a1
    K2 = k2
    A2 = a2
else:
    K1 = k2
    A1 = a2
    K2 = k1
    A2 = a1

max1 = n//K1
max3 = 0
if(max1 > A1):
    max1 = A1
    max2 = n - max1*K1
    #print(max2,A2)
    max3 = max2//K2
    if(max3 > A2):
        max3 = A2
#print(max1,max3)
print(min1,max1+max3)