t = int(input())
for i in range(t):
    s = ''.join(sorted(input()))
    if s == s[::-1]:
        print(-1)
    else:
        print(s)