t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    ans = 0
    while 10 ** (ans+1) - 1 <= b:
        ans += 1
    print(ans * a)