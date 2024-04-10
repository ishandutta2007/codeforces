a = list(map(int, input().split()))
b = ["Valera", "Vladik"]
a = a[::-1]
for i in range(1, 1000100):
    j = i % 2
    if a[j] >= i:
        a[j] -= i
    else:
        print(b[j])
        break