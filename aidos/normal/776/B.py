n = int(input())
n += 2
u = [1] * n
for i in range(2, n):
    if u[i] == 1:
        for j in range(i*i, n, i):
            u[j] = 2

print(max(u[2:]))
print(' '.join(map(str, u[2:])))