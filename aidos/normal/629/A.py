n = int(input())
b = [0] * n
c = [0] * n
for i in range(n):
    t = input()
    for j in range(n):
        if t[j] == 'C':
            b[i] += 1
            c[j] += 1
ans = 0
for i in range(n):
    ans += (b[i] * (b[i]-1))//2
    ans += (c[i] * (c[i]-1))//2
print(ans)