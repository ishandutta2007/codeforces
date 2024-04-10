n = int(input())
arr = ['.' * (n + 2)] + ['.' + input() + '.' for i in range(n)] + ['.' * (n + 2)]
ans = 0
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if arr[i][j] == arr[i - 1][j - 1] == arr[i - 1][j + 1] == arr[i + 1][j - 1] == arr[i + 1][j + 1] == 'X':
            ans += 1
print(ans)