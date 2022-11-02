n = int(input())
a = list(map(int, input().split()))
last = 0
cnt = 0
for i in range(1, 91):
    if i - last > 15:
        break
    cnt += 1
    if i in a:
        last = i
print(cnt)