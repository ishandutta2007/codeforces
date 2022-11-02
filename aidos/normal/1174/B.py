n = int(input())
a = list(map(int, input().split()))
b = set(i % 2 for i in a)
if len(b) != 1:
    a = sorted(a)
for i in a:
    print(i, end = ' ')