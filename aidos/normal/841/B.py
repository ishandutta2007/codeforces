n = int(input())
a = map(int, input().split())
ans = 0
for x in a:
    ans += x % 2
if ans > 0:
    print('First')
else:
    print('Second')