n = int(input())
p = list(map(int, input().split()))
for i in range(n):
    p[i] -= 1
for i in range(n):
    u = [False] * n
    j = i
    while u[j] == False:
        u[j] = True
        j = p[j]
    print(j+1, end = ' ')