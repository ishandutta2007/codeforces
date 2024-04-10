n = int(input())
a = str(n)
ans = 9 ** (len(a) - 1)
cur = 1
curL = len(a)
for x in a:
    curL-=1
    if int(x) > 1:
        ans = max(ans, cur * (int(x) - 1) * (9**curL))
    cur *= int(x)
print(max(ans, cur))