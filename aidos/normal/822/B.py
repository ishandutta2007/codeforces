n, m = map(int, input().split())
s = input()
t = input()
z = -1
g = n + 1
for i in range(m-n+1):
    c = 0
    for j in range(n):
        if s[j] != t[i+j]:
            c += 1
    if c < g:
        g = c
        z = i
print(g)
print(' '.join([str(i+1) for i in range(n) if s[i] != t[i+z] ]))