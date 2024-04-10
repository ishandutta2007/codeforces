n = int(input())
ans1 = []
ans2 = []
for i in range(n):
    if i % 2 == 0:
        ans1.append(2*i+1)
        ans2.append(2*i+2)
    else:
        ans1.append(2*i+2)
        ans2.append(2*i+1)
ans = ans1 + ans2
s = set()
x = sum(ans[:n])
s.add(x)
for i in range(2*n):
    x -= ans[i]
    x += ans[(i+n) % (2*n)]
    s.add(x)
if len(s) == 2:
    print('YES')
    print(' '.join(map(str, ans)))
else:
    print('NO')