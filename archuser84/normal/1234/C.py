for _ in range(int(input())):
    n = int(input())
    s = ['']*2
    s[0] = input()
    s[1] = input()
    p = 0
    for i in range(n):
        if s[p][i] > '2':
            p = 1 - p
            if s[p][i] <= '2':
                p = 0
                break
    print('YES' if p else 'NO')