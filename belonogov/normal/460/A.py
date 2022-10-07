

a = input().split(' ')
n = int(a[0])
m = int(a[1])
ans = 0
d = 1;
while n > 0: 
    ans += 1
    n -= 1
    n += (d % m) == 0
    d += 1

print(ans)