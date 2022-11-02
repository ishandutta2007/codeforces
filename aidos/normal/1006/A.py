n = int(input())

a = map(int, input().split())

ans = ''

for x in a:
    if x % 2 == 0:
        x -= 1
    ans += ' ' + str(x)
print(ans)