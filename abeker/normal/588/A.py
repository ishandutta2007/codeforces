N = int(input())
sol = 0
m = 101
for i in range(N):
    a, b = map(int, input().split())
    m = min(m, b)   
    sol += a * m
print(sol)