t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))[::-1]
    m = 10**7
    ans = 0
    for x in a:
        if x > m:
            ans += 1
        else:
            m = x
    print(ans)