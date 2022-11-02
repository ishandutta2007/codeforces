n, k = map(int, input().split())
i = 2
nn = n
a = []
for i in range(2, n+1):
    while nn % i == 0:
        if k > 1:
            a.append(i)
            nn //= i
        elif i == nn:
            a.append(i)
            nn//=i
        else:
            break
        k -= 1
if k == 0:
    for i in a:
        print(i, end = ' ')
else:
    print(-1)