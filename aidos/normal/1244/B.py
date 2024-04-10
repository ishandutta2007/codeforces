def solve(n, s):
    ans = n
    last = -1
    for i in range(n):
        if s[i] == '1':
            ans = max(ans, i*2+2)
            last = i
    x, y = 1, 0
    if s[0] == '1':
        y = 2
        ans = 2 * n
    if last > 0:
        ans = max(max(x, y) + last * 2, ans)
    for i in range(2, n):
        if s[i] == '1':
            x, y = max(y+2, x+1), max(x+2, y+1)
        else:
            x, y = x+1, y+1
        if i < last:
            ans = max(max(x, y)+(last-i)*2, ans)
    return max(ans, x, y)


t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    ans = solve(n, s)
    s = s[::-1]
    ans = max(ans, solve(n, s))
    print(ans)