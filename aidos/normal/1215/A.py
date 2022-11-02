a, b, x, y, n = [int(input()) for _ in range(5)]
z = n - a * (x-1) - b * (y-1)
t1 = min(n//x, a)
t2 = min(n//y, b)
k = max(t1 + min((n-x*t1)//y, b), t2 + min((n-y*t2)//x, a))

print(max(0, z), k)