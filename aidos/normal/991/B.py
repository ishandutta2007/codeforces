n = int(input())
a = sorted(map(int, input().split()))
cnt = 0
while sum(a)*2 < 9*n:
    a = sorted(a)
    a[0] = 5
    cnt += 1
print(cnt)