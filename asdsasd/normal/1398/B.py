for _ in range(int(input())):
    s = input()
    lst = []
    cnt = 0
    for ss in s:
        if ss == "1":
            cnt += 1
        else:
            lst.append(cnt)
            cnt = 0
    if cnt != 0:
        lst.append(cnt)
    ans = 0
    lst.sort(reverse = True)
    for i in range(0, len(lst), 2):
        ans += lst[i]
    print(ans)