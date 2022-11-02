t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    s = set()
    for i in range(0, n):
        s.add((a[i] - a[i-1]) % n)
    if len(s) == 1 and (1 in s or n-1 in s):
        print('YES')
    else:
        print('NO')