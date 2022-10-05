def solve():
    l = int(input())
    val = int(input())
    m = list()
    ans = list()
    for i in range(l):
        m.append(val % 10)
        val //= 10
        if (m[i] % 2):
            ans.append(m[i])
    ans.reverse()
    while (len(ans) > 2):
        ans.pop()
    if (len(ans) > 1):
        for i in ans:
            print(i, end = '')
        print()
    else:
        print(-1)
        

t = int(input())
while (t):
    solve()
    t -= 1