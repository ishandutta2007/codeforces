t = int(input())
while t:
    n = int(input())
    v = list(map(int, input().split()))
    sum = 0
    ans = 0
    for i in v:
        sum += i
        ans = max(ans, -sum)
    print(ans)
    t -= 1