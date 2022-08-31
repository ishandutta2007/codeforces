n = int(input())
l = list(map(int,input().split()))
m = max(l)
min = 100000000
for p in range(1,m+1):
    sum = 0
    for i in l:
        if(i < p):
            sum += p-i-1
        elif(i > p):
            sum += i-p-1
    if(sum < min):
        min = sum
        p1 = p
print(p1,min)