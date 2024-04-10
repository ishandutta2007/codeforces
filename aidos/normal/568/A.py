p, q= map(int, input().split())
L = 2 * 10 ** 6 + 10 ** 5
P = [0] * L

for i in range(2, L, 1):
    if P[i] == 0:
        for j in range(i*i, L, i):
            P[j] = 1
ans = -1
P[1] = 1
cnta = 0
cntb = 0
for i in range(1, L):
    if P[i] == 0:
        cnta += 1
    j = str(i)
    if j == j[::-1]:
        cntb += 1
    if cnta * q <= p * cntb:
        ans = i
print(ans)