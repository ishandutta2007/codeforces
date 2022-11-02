n = int(input())
a = list(map(int, input().split()))
cnt = 0
d = 0
while len(a) > 0:
    b = []
    for i in range(len(a)):
        if a[i] <= d:
            d += 1
        else:
            b.append(a[i])
    a = b[::-1]
    cnt += 1
print(cnt-1)