def pp(a, b, c):
    t = map(str, a) + ['+'] + map(str, b) + ['='] + map(str, c)
    print (''.join(t))
def go(s, a, b, i):
    if i != 1 and s[-i] == 0:
        return 0
    if a != 1 and s[0] == 0:
        return 0
    if b != 1 and s[a] == 0:
        return 0
    if max(a, b) < i:
        if not a == b and not (a == i - 1 and s[0] == 9) and not (b == i - 1 and s[a] == 9):
            return 0
        if s[-i] != 1:
            return 0
        t = 1
        if a == i - 1:
            for j in xrange(a-b):
                t = t * 10 + s[-a+j] - s[j]
                if t < 0 or t > 1:
                    return 0
            for j in xrange(b):
                t = t * 10 + s[-b+j] - s[a-b+j] - s[a+j]
                if t < 0 or t > 1:
                    return 0
            if t == 0:
                pp(s[:a], s[a:a+b], s[-i:])
                return 1
            return 0
        else:
            for j in xrange(b-a):
                t = t * 10 + s[-b+j] - s[a+j]
                if t < 0 or t > 1:
                    return 0
            for j in xrange(a):
                t = t * 10 + s[-a+j] - s[j] - s[a+b-a+j]
                if t < 0 or t > 1:
                    return 0
            if t == 0:
                pp(s[:a], s[a:a+b], s[-i:])
                return 1
            return 0
    else:
        if a == i:
            t = 0
            for j in xrange(i-b):
                t = t * 10 + s[-a+j] - s[j]
                if t < 0 or t > 1:
                    return 0
            for j in xrange(b):
                t = t * 10 + s[-b+j] - s[i-b+j] - s[a+j]
                if t < 0 or t > 1:
                    return 0
            if t == 0:
                pp(s[:a], s[a:a+b], s[-i:])
                return 1
            return 0
        else:
            t = 0
            for j in xrange(i-a):
                t = t * 10 + s[-b+j] - s[a+j]
                if t < 0 or t > 1:
                    return 0
            for j in xrange(a):
                t = t * 10 + s[-a+j] - s[j] - s[a+i-a+j]
                if t < 0 or t > 1:
                    return 0
            if t == 0:
                pp(s[:a], s[a:a+b], s[-i:])
                return 1
            return 0
def main():
    s = map(int,raw_input().strip())
    l = len(s)
    mod = 10007
    t = [0] * (l + 1)
    u = [1] * (l + 1)
    for i in xrange(l):
        u[i+1] = u[i] * 10 % mod
        t[i+1] = (t[i] * 10 + s[i]) % mod
    for i in xrange(1, l - 1):
        a, b = i - 1, l - i - i + 1
        hi = (t[l] - t[l-i] * u[i]) % mod
        if 1 <= b <= i:
            if hi == (t[a] + (t[a+b] - t[a] * u[b])) % mod and go(s, a, b, i):
                return
            if hi == (t[b] + (t[a+b] - t[b] * u[a])) % mod and go(s, b, a, i):
                return
        a += 1
        b -= 1
        if 1 <= b <= i:
            if hi == (t[a] + (t[a+b] - t[a] * u[b])) % mod and go(s, a, b, i):
                return
            if hi == (t[b] + (t[a+b] - t[b] * u[a])) % mod and go(s, b, a, i):
                return
main()