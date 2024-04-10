

def solve():
    n = int(input())
    a = sorted(map(int, input().split()))
    b = sorted(map(int, input().split()))
    for i in range(n):
        if a[i] > b[i] or a[i] < b[i] - 1:
            print("NO")
            break
    else:
        print("YES")




t = int(input())
for i in range(t):
    solve()