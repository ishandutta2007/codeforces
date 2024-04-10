for _ in range(int(input())):
    n = int(input())
    s = input()
    res = []
    ones = []
    zeros = []
    ans = 0
    for c in s:
        if c == '0':
            if len(ones) == 0:
                ans += 1
                zeros.append(ans)
                res.append(ans)
            else:
                x = ones[len(ones) - 1]
                ones.pop()
                zeros.append(x)
                res.append(x)
        else:
            if len(zeros) == 0:
                ans += 1
                ones.append(ans)
                res.append(ans)
            else:
                x = zeros[len(zeros) - 1]
                zeros.pop()
                ones.append(x)
                res.append(x)
    print(ans)
    for k in res:
        print(k, end = ' ')
    print()