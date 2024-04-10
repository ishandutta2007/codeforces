q = int(input())

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n - 1):
        mx = a[i + 1]
        mx_idx = i + 1
        for j in range(i + 1, n):
            if a[i] < mx > a[j]:
                print('YES')
                print(i + 1, mx_idx + 1, j + 1)
                return
            if a[j] > mx:
                mx = a[j]
                mx_idx = j
    print('NO')

for test in range(q):
    solve()