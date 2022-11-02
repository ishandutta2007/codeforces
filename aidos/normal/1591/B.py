

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    lst = a[n-1]
    cnt = 0
    for i in range(n-2, -1, -1):
        if lst < a[i]:
            lst = a[i]
            cnt += 1
    print(cnt)




t = int(input())
for i in range(t):
    solve()