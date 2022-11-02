a, b = map(int, input().split())

cnt = 0
while a <= b:
    cnt += 1
    a *= 3
    b *= 2
print(cnt)