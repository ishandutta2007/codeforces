def comp(x):
    for i in range(2, x):
        if x % i == 0:
            return True
    return False

N = int(input())

if N == 4:
    print('YES', '1', '3', '2', '4', sep = '\n')
elif comp(N):
    print('NO')
else:
    print('YES', '1', sep = '\n')
    if N > 1:
        for i in range(2, N):
            print((i - 1) * pow(i, N - 2, N) % N)
        print(N)