a, b = map(int, input().split())
ans = 1
a += 1
while a <= b and ans > 0:
    ans = (ans * a) % 10
    a += 1
print(ans)