n, m, k = map(int , input().split())
k -= 1
z = k//2
x = z//m
y = z % m

print(x + 1, y + 1, ('L', 'R')[k % 2])