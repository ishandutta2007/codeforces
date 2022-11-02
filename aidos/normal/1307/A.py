t = int(input())
for _ in range(t):
    n, d = map(int, input().split())
    a = list(map(int, input().split()))
    for x in range(d):
        for i in range(1, n):
            if a[i] > 0:
                a[i] -= 1
                a[i-1] += 1
                break
    print(a[0])