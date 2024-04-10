q  = int(input())
for i in range(q):
    n = int(input())
    a = map(int, input().split())
    cnt = [0]*3
    for x in a:
        cnt[x % 3] += 1
    ans = 0
    ans += cnt[0]
    d = min(cnt[1], cnt[2])
    ans += d
    ans += (cnt[1]-d)//3
    ans += (cnt[2]-d)//3
    print(ans)