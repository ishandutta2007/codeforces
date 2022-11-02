n, k = map(int, input().split())
a = input().split()
b = input().split()
for i in a:
    if i in b:
        print(i, end = ' ')