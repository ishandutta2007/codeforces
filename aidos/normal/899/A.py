n=int(input())
a = map(int, input().split())
c = 0
for x in a:
    if x==1:
        c += 1
d = n - c
ans = min(c,d)
c -= min(c, d)
print(ans + c//3)