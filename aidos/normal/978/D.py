n = int(input())
a = list(map(int, input().split()))
if n <= 2:
    print(0)
else:
    ans = -1
    for i in range(-1, 2):
        for j in range(-1, 2):
            b = []
            x = a[0] + i
            d = a[1] + j - a[0]  - i
            for t in range(n):
                b.append(t * d + x)
            good=1
            cur = 0
            for t in range(n):
                if abs(a[t] - b[t]) > 1:
                    good = 0
                cur += abs(a[t] - b[t])
            if good:
                if ans == -1:
                    ans = cur
                else:
                    ans = min(ans, cur)
    
    print(ans)