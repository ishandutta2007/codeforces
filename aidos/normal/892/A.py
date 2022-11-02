n = int(input())
a = map(int, input().split())
b = sorted(map(int, input().split()))
if sum(a) <= b[-1] + b[-2]:
    print('YES')
else:
    print('NO')