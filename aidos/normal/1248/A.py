t = int(input())
for _ in range(t):
    n = int(input())
    a = map(int, input().split())
    m = int(input())
    b = map(int, input().split())
    cnt = [0, 0]
    for x in a:
        cnt[x % 2] += 1
    ans = 0
    for x in b:
        ans += cnt[x % 2]
    print(ans)