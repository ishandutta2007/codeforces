t = int(input())
for i in range(t):
    a, b, n, S = map(int, input().split())
    x = min(S//n, a)
    if S - x * n  <= b:
        print("YES")
    else:
        print("NO")