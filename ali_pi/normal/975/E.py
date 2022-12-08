from sys import*
from math import*
def main():
    n, q = stdin.readline().split()
    n = int(n)
    q = int(q)
    lines = stdin.readlines()
    x = [0] * (n + 1)
    y = [0] * (n + 1)
    for i in range(n):
        x[i], y[i] = lines[i].split()
        x[i] = int(x[i])
        y[i] = int(y[i])
    x[n] = x[0]
    y[n] = y[0]
    a = 0
    cx = 0
    cy = 0
    for i in range(n):
        ii = i + 1
        a += x[i] * y[ii] - x[ii] * y[i]
        cx += (x[i] + x[ii]) * (x[i] * y[ii] - x[ii] * y[i])
        cy += (y[i] + y[ii]) * (x[i] * y[ii] - x[ii] * y[i])
    a *= 3
    r = [0.0] * n
    z = [0.0] * n
    for i in range(n):
        x[i] = x[i] * a - cx
        y[i] = y[i] * a - cy
        r[i] = sqrt(x[i] * x[i] + y[i] * y[i]) / a
        z[i] = atan2(y[i], x[i])
    cx /= a
    cy /= a
    p = [0, 1]
    mt = 0.0
    for i in range(q):
        tmp = lines[n + i].split()
        ta = int(tmp[0])
        tb = int(tmp[1])
        if ta == 1:
            ta = int(tmp[2])
            ta -= 1
            tb -= 1
            if p[0] == tb:
                p[0], p[1] = p[1], p[0]
            p[1] = ta
            tc = z[p[0]] + mt
            cx += r[p[0]] * cos(tc)
            cy += r[p[0]] * (sin(tc) - 1)
            tc = pi / 2 - tc;
            mt = pi / 2 - z[p[0]];
        else:
            tb -= 1
            tc = z[tb] + mt
            stdout.write('%.10lf %.10lf\n' % (cx + r[tb] * cos(tc), cy + r[tb] * sin(tc)))

if __name__ == '__main__':
    main()