from sys import stdout

size = int(input())

xlim = size
ylim = size
a = [(0, ylim), (xlim, 0)]

cnt = 0

while True:
    cnt += 1

    sq = 0
    n = len(a)

    for i in range(n - 1):
        sq += (a[i + 1][0] - a[i][0]) * a[i + 1][1]

    lf = 0
    rg = xlim * ylim - sq + 1

    x = 0
    y = 0

    flag = True

    while flag:
        if rg - lf == 1:
            flag = False

        mid = (lf + rg) // 2

        # print(lf, rg, mid)

        cur = 0
        x = -1
        nx = 0

        for i in range(n - 2, -1, -1):
            add = (a[i + 1][0] - a[i][0]) * (ylim - a[i + 1][1])
            if add + cur < mid:
                cur += add
            else:
                x = a[i + 1][0] - ((mid - cur - 1) // (ylim - a[i + 1][1]) + 1)
                assert(x >= 0)
                break

        for i in range(n - 2, -1, -1):
            if x + 1 < a[i][0]:
                nx += (a[i + 1][0] - a[i][0]) * a[i + 1][1]
            else:
                nx += (a[i + 1][0] - (x + 1)) * a[i + 1][1]
                break

        cur = 0
        y = -1
        ny = 0

        for i in range(0, n - 1):
            add = (a[i][1] - a[i + 1][1]) * (xlim - a[i][0])
            if add + cur < mid:
                cur += add
            else:
                y = a[i][1] - ((mid - cur - 1) // (xlim - a[i][0]) + 1)
                assert(y >= 0)
                break

        for i in range(0, n - 1):
            if a[i + 1][1] > y + 1:
                ny += (a[i][1] - a[i + 1][1]) * a[i][0]
            else:
                ny += (a[i][1] - (y + 1)) * a[i][0]
                break

        rem = (x + 1) * (y + 1) - (sq - nx - ny)
        for i in range(n):
            if a[i][0] >= x + 1 and a[i][1] >= y + 1:
                rem = 0

        # print(x, y)
        # print(nx, ny)
        # print(rem)

        if rem >= mid:
            lf = mid
        else:
            rg = mid

    print(size - x, size - y)
    stdout.flush()
    tp = int(input())

    if tp == 0:
        break
    elif tp == 1:
        xlim = x
        mx = 0
        na = []

        for el in a:
            if el[0] < xlim:
                na.append(el)
            else:
                mx = max(mx, el[1])
        na.append((xlim, mx))
        na.append((xlim, 0))
        a = na.copy()

    elif tp == 2:
        ylim = y
        mx = 0
        na = []

        for el in a:
            if el[1] >= ylim:
                mx = max(mx, el[0])
        na.append((0, ylim))
        na.append((mx, ylim))

        for el in a:
            if el[1] < ylim:
                na.append(el)
        a = na.copy()

    elif tp == 3:
        na = []
        for el in a:
            if el[1] >= y + 1:
                na.append(el)
        na.append((x + 1, y + 1))
        for el in a:
            if el[0] >= x + 1:
                na.append(el)
        a = na.copy()

    # print(a)