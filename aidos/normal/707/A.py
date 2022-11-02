n, m = map(int, input().split())
ans = '#Black&White'
for i in range(n):
    x = input()
    if 'C' in x or 'Y' in x or 'M' in x:
        ans = '#Color'
print(ans)