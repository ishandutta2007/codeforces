a = list(map(int, input().split()))
mx = max(a)
a.remove(mx)

for i in range(3):
    print(mx - a[i], sep = ' ')