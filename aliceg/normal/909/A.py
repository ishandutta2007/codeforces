a, b = input().split()
k = 1
for i in range(1, len(a)):
    if a[i] < b[0]:
        k += 1
    else:
        break
ans = a[:k] + b[0]
print(ans)