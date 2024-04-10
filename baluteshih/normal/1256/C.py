data = input().split(' ')
n, m, d = int(data[0]), int(data[1]), int(data[2])
arr = list(map(int, input().split(' ')))
ans = [0]*(n+1)
sum = 0
for i in arr:
    sum += i
nw = 0
for idx, i in enumerate(arr):
    if n+1-sum <= nw+d:
        for j in range(i):
            ans[n+1-sum+j] = idx+1
        sum -= i
        nw = n+1-sum
    else:
        for j in range(i):
            ans[nw+d+j] = idx+1
        sum -= i
        nw = nw+d+i-1
if nw+d < n+1:
    print('NO')
else:
    print('YES')
    print(*ans[1:])