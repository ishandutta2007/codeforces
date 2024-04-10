n = int(input())
c = 0
for i in range(n):
    c += 1
    s, d = map(int, input().split())
    c = c + (s-c) % d
    c = max(s, c)
print(c)