n = int(input())

for i in range(n):
    l1, r1, l2, r2 = map(int, input().split())
    a = l1
    b = l2
    if a == b:
        b += 1
    print(a, b)