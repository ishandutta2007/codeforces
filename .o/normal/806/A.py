T = int(input())
for _ in range(T):
    x, y, p, q = map(int, input().split())
    if p == 0:
        print(0 if x == 0 else -1)
    elif p < q:
        m = max(
            (x + p-1) // p,
            (y + q-1) // q,
            (y-x + q-p-1) // (q-p)
        )
        print(q * m - y)
    else:
        print(0 if x == y else -1)