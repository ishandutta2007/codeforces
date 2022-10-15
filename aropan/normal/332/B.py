n, k =  map(int, raw_input().split())
a = map(int, raw_input().split())
a = [0] + a
for i in range(1, len(a)):
    a[i] += a[i - 1];

b = []
for i in range(n - k + 1):
    b.append(a[i + k] - a[i])
    
x = 0
y = k
m = 0
for i in range(k, len(b)):
    m = i - k if b[m] < b[i - k] else m
    if b[x] + b[y] < b[m] + b[i]:
        x = m
        y = i
print x + 1, y + 1