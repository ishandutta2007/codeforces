n = int(input())
a = list(map(int,input().split()))
a.sort()
t = 0
ksr = 0
tm = 0
for i in range(n):
    #m = sum(a[:i])-ksr
    m = tm
    if m <= a[i]:
        t += 1
        tm += a[i]
    else :
        ksr += a[i]
print(t)