n = int(input())
p = list(map(int, input().split()))
cnt = 0
for i in range(n):
    if p[p[i]-1] == i+1 and p[i] <= i + 1:
        cnt += 1
print(cnt)