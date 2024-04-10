a = list(map(int, input().split()))
for i in range(3):
    a[i] -= i

print(min(a)*3 + 3)