def rec(l, r, a, A, B):
    if len(a) == 0:
        return A
    cur = len(a) * B * (r-l+1)
    if l == r:
        return cur
    b = []
    c = []
    mid = (l+r)//2
    for i in a:
        if i <= mid:
            b.append(i)
        else:
            c.append(i-mid-1)
    return min(rec(l, mid, b, A, B)+rec(l, mid, c, A, B), cur)

n, k, A, B = map(int, input().split())
a = list(map(int, input().split()))
for i in range(k):
    a[i] -= 1
print(rec(0, (2**n) - 1, a, A, B))