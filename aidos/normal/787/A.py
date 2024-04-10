b, a = map(int, input().split())
d, c = map(int, input().split())
ans = -1

for i in range(100100):
    if i >= a and i >= c and i % b == a % b and i % d == c % d and ans == -1:
        ans = i
print(ans)