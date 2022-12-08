f = lambda: map(int,raw_input().split())
q = f()[1]
a = f()
d = [f() for i in range(q)][::-1]
for k in f():
    for t, l, r in d:
        if l <= k <= r: k = l + r - k if t == 2 else r if k == l else k - 1
    print str(a[k - 1])