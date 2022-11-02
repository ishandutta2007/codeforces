t = int(input())
for _ in range(t):
    ans = 0
    n = int(input())
    s = input()
    last = n + 1
    for i in range(n):
        if s[i] == 'P':
            ans=max(ans, i - last)
        else:
            last = i
    print(ans)