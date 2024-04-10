n, a, b, c, t = map(int, input().split())
ans = 0
d=list(map(int, input().split()))
print(max((c-b) * (t * n - sum(d)), 0) + a * n)