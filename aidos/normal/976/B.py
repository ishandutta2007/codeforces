n,m, k = map(int, input().split())
if k < n:
    print(k+1, 1)
else:
    k -= n
    if m == 2:
        print(n-k,2)
    else:
        d = k//(2*(m-1))
        x = n
        y = 2
        x -= 2 * d
        k -= d * (2*(m-1))
        if k < m-1:
            y += k
        else:
            k -= m-1
            y = m-k
            x -= 1
        print(x, y)