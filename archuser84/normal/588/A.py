ans = 0
k = 100
for i in range(int(input())):
    a,p = map(int,input().split())
    k = min(k, p)
    ans += a*k
print(ans)