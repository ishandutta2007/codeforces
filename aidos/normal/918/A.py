f = [1, 1]
for j in range(60):
    f.append(f[-1] + f[-2])
n = int(input())
for i in range(n):
    if (i+1) in f:
        print('O', end='')
    else:
        print('o', end='')