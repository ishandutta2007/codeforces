from sys import*
from bisect import*
n, q = map(int, raw_input().split())
coins = map(int, raw_input().split())
d = {1 << i : 0 for i in xrange(31)}
for num in coins:
    d[num] += 1
inp = stdin.readlines()
out = []
for line in inp:
    b = int(line.strip())
    ans = 0
    p = 30
    while p >= 0:
        val = 1 << p
        if val <= b:
            sub = min(d[val], b // val)
            ans += sub
            b = b - val * sub
        p -= 1
        
    if b == 0: out.append(str(ans))
    else: out.append(str("-1"))
stdout.write('\n'.join(out))