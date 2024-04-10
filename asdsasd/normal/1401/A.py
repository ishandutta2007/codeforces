t = int(input())
for _ in range(t):
    n, k = map(int, input().split())

    if n % 2 != k % 2:
        ans = 1
        n += 1
    else:
        ans = 0
    if k > n:
        print(k - n + ans)
    else:
        print(ans)