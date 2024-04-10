k = int(input())

a = []
sum = []
for i in range(1, 10):
    a.append(i)
    sum.append(i)
ans = -1
while ans == -1:
    A = []
    S = []
    for i in range(len(a)):
        for j in range(10):
            if sum[i] + j <= 10:
                A.append(a[i] * 10 + j)
                S.append(sum[i] + j)
    a = A
    sum = S
    for i in range(len(a)):
        if sum[i] == 10:
            k -= 1
            if k == 0:
                ans = a[i]
                break
print(ans)