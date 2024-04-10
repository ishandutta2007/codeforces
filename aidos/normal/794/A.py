a, b, c = map(int, input().split())
n = int(input())
d = list(map(int, input().split()))
s = 0
for i in d:
    if i > b and i < c:
        s += 1
print(s)