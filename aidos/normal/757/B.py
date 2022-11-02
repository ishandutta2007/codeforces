n = int(input())
a = map(int, input().split())
ans = 1
c = [0] * 100100
for i in a:
    c[i] += 1

for i in range(2, 100100):
    ans = max(ans, sum(c[i::i]))
print(ans)