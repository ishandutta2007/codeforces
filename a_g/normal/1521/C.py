def ask(t, i, j, x):
    print("?", t, i, j, x)
    return int(input())

for _ in range(int(input())):
    n = int(input())
    mxindex = n-1
    p = [0]*n
    for i in range(0, n-1, 2):
        k = ask(1, i+1, i+2, n-1)
        if k == n:
            mxindex = i+1
            break
        elif k == n-1:
            if ask(1, i+2, i+1, n-1) == n:
                mxindex = i
                break
    p[mxindex] = n
    for i in range(n):
        if i == mxindex:
            continue
        p[i] = ask(2, i+1, mxindex+1, 1)
    print("!", *p)