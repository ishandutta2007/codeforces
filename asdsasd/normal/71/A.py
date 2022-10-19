for _ in range(int(input())):
    s = input()
    if len(s) <= 10:
        print(s)
    else:
        ans = s[0] + str(len(s) - 2) + s[-1]
        print(ans)