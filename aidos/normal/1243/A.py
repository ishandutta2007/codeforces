t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().split()))[::-1]
    ans = 0
    for i in range(n):
        if a[i] > i:
            ans = i
    print(ans + 1)