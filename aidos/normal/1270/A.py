t = int(input())
for _ in range(t):
    x = input()
    a = map(int, input().split())
    b = map(int, input().split())
    if max(a) > max(b):
        print('YES')
    else:
        print('NO')