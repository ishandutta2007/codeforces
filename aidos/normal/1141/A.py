n, m = map(int, input().split())
good = True
if m % n != 0:
    good = False
m //= n
cnt = 0
while m % 2 == 0:
    m//=2
    cnt += 1
while m % 3 == 0:
    m//=3
    cnt += 1
if m == 1 and good:
    print(cnt)
else:
    print(-1)