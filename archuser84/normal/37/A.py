n = int(input())
l = input().split()
maax = 0
ans = 0
for i in range(1 , 1001):
    x = l.count(str(i))
    if x > maax:
        maax = x
    if x > 0:
        ans = ans + 1
print(str(maax) + ' ' + str(ans))