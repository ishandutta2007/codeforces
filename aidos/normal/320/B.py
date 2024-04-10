n = int(input())
c = []
ind = 1
for i in range(n):
    x, a, b = map(int, input().split())
    if x == 1:
        c.append([a, b])
    else:
        u = [False] * len(c)
        g = [0] * len(c)
        l = 0
        r = 1
        g[l] = a-1
        u[a-1] = True
        while l < r:
            h = g[l]
            l += 1
            x, y = c[h]
            for j in range(len(c)):
                if ((c[j][0] < x and x < c[j][1]) or (c[j][0] < y and y < c[j][1])) and u[j] == False:
                    g[r] = j
                    u[j] = True
                    r += 1
        
        if u[b-1]:
            print('YES')
        else:
            print('NO')