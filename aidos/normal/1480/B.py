

def solve():
    A, B, n = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    mx = max(a)
    s = 0
    for i in range(n):
        c = (b[i] + A - 1)//A
        s += a[i] * c
    if s - mx < B:
        print("YES")
    else:
        print("NO")




t = int(input())
for i in range(t):
    solve()