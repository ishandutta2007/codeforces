

def solve():
    n = int(input())
    a = sorted(map(int, input().split()))
    if sum(a) == 0:
        print("NO")
    else:
        if sum(a) > 0:
            a = a[::-1]
        print("YES")
        print(" ".join(map(str, a)))






t = int(input())
for i in range(t):
    solve()