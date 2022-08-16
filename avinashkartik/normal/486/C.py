n,p = map(int,input().split())
l = list(input())
flag = 0
min1 = max1 = -1
sum = 0
for i in range(n//2):
    if(l[i] != l[n-1-i]):
        if(flag == 0):
            min1 = i+1
            flag = 1
        max1 = i+1
        s1 = abs(ord(l[i]) - ord(l[n-1-i]))
        s2 = 26 - s1
        sum += min(s1,s2)
if(p > n//2):
    p = n + 1 - p
if(max1 != -1):
    sum += min(abs(max1-p),abs(p-min1))
    sum += max1 - min1
print(sum)