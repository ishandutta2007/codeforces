q=int(input())
for i in range(q):
    n = int(input())
    cnt = 0
    while n % 5 == 0:
        n //= 5
        cnt += 3
    while n % 3 == 0:
        n //= 3
        cnt += 2
    while n % 2 == 0:
        n //= 2
        cnt += 1
    if n == 1:
        print(cnt)
    else:
        print(-1)