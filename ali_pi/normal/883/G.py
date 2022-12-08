import sys
def main():
    n, m, s = map(int, sys.stdin.readline().split())
    s -= 1
    x = [[] for i in range(n)]
    un = []
    j = 0
    for i in range(m):
        t, u, v = map(int, sys.stdin.readline().split())
        u -= 1
        v -= 1
        if t == 1:
            x[u].append([1, v, -1])
        else:
            x[u].append([2, v, j])
            x[v].append([2, u, j])
            un.append((u, v))
            j += 1
    q = [s]
    u = [False] * n
    u[s] = True
    um = [False] * len(un)
    b = ['-'] * len(un)
    ci = 0
    while ci < len(q):
        c = q[ci]
        ci += 1
        for i in range(len(x[c])):
            t, to, j = x[c][i]
            if not u[to]:
                if t == 1:
                    q.append(to)
                    u[to] = True
                elif not um[j]:
                    um[j] = True
                    if c == un[j][0]:
                        b[j] = '+'
                    q.append(to)
                    u[to] = True
    a = 0
    for i in range(n):
        if u[i]:
            a += 1
    print(a)
    print(''.join(b))

    q = [s]
    u = [False] * n
    u[s] = True
    um = [False] * len(un)
    b = ['-'] * len(un)
    ci = 0
    while ci < len(q):
        c = q[ci]
        ci += 1
        for i in range(len(x[c])):
            t, to, j = x[c][i]
            if not u[to]:
                if t == 1:
                    q.append(to)
                    u[to] = True
                elif not um[j]:
                    um[j] = True
                    if c != un[j][0]:
                        b[j] = '+'
    a = 0
    for i in range(n):
        if u[i]:
            a += 1
    print(a)
    print(''.join(b))
main()