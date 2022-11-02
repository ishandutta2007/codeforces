t = int(input())
for i in range(t):
    s, a, b, c=map(int, input().split())
    ans = s//c
    ans += (ans//a) * b
    print(ans)