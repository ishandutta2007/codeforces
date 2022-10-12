n,  =tuple(int(i) for i in raw_input().split())
 
b = tuple(int(i) for i in raw_input().split())
 
ans = n + 5

def check(f, s):
    start = b[0] + f
    end = b[-1] + s
    if (end - start) % (n-1) != 0:
        return n + 5
    incr = (end - start) / (n-1)
    res = abs(f) + abs(s)
    for i in range(1, n - 1):
        t = start + incr * i
        d = abs(b[i] - t)
        if d > 1:
            return n + 5
        res += d
    return res

if n > 1:
    for f in [-1, 0, 1]:
        for s in [-1, 0, 1]:
            ans = min(ans, check(f, s))
else:
    ans = 0

if ans == n + 5:
    print -1
else:
    print ans