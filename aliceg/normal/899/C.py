n = int(input())
ans = []
flag = 0
if n % 2:
    n -= 1
    flag = 1
if (n % 4 == 0 and not flag) or (n % 4 and flag):
    print(0)
    for i in range(n // 2):
        if i % 2 == 0:
            ans.append(i + 1)
            ans.append(n - i)
    print(len(ans), end=' ')
    for i in ans:
        print(i, end=' ')
else:
    print(1)
    for i in range(n // 2 - 1):
        if i % 2 == 0:
            if i % 2 == 0:
                ans.append(i + 1)
                ans.append(n - i)
    ans.append(n // 2 + 1)
    print(len(ans), end=' ')
    for i in ans:
        print(i, end=' ')