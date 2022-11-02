import math
n, m = map(int, input().split())
a = []
for i in range(1, n+1):
    j = i + 1
    while len(a) < m and j <= n:
        if math.gcd(i, j) == 1:
            a.append([i, j])
        j += 1

if len(a) != m or m < n-1:
    print("Impossible")
else:
    print('Possible')
    for i in a:
        print(i[0], i[1])