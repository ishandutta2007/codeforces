n = int(input())
a = []
for i in range(n):
    x, y = map(int, input().split())
    a.append(x+y)
print(max(a))