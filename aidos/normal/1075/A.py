n = int(input())
x, y = map(int, input().split())
if x-1+y-1 <= n-x + n - y:
    print('White')
else:
    print('Black')