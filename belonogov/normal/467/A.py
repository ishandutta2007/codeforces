

n = int(input())
a = [0] * n
b = [0] * n
for i in range(0, n):
    r = input().split(' ')
    a[i] = int(r[0])
    b[i] = int(r[1])


cnt = 0;
for i in range(0, n):
    cnt += 1 if a[i] + 2 <= b[i] else 0

print(cnt)