n = int(input())
a = sorted(map(int, input().split()))
if sum(a) % 2 != 0 or sum(a) - a[-1] < a[-1]:
    print('NO')
else:
    print('YES')