def check(k, n, w):
    global a
    if w < 0:
        return 0
    if w == 0 and k == 0:
        return 1
    if k == 0:
        return 0
    if n == 0:
        return 0
    if check(k - 1, n - 1, w - a[6 - n]) or check(k, n - 1, w):
        return 1
    return 0
        


a = list(map(int, input().split()))
s = sum(a)
if s % 2:
    print('NO')
elif check(3, 6, s // 2):
    print("YES")
else:
    print("NO")