n = int(input())
a = map(int, input().split())
ans = 0
s = 0
z = 0
for x in a:
    if x < 0:
        ans += -1-x
        s += 1
    elif x == 0:
        ans += 1
        z += 1
    else:
        ans += x-1
if s % 2 == 1 and z == 0:
    ans += 2
print(ans)