a, b = input().split()
n = int(input())
for i in range(n):
    print(a, b)
    c, d = input().split()
    if a == c:
        a = d
    elif a == d:
        a = c
    elif b==c:
        b = d
    else:
        b = c
print(a, b)