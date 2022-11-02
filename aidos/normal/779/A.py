

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
d = dict()
for x in a:
    d[x] = d.get(x, 0) + 1
for x in b:
    d[x] = d.get(x, 0) - 1

ans = 0
cnt = 0
for k, v in d.items():
    ans += abs(v)
    cnt += v % 2
if cnt > 0:
    print(-1)
else:
    print(ans//4)