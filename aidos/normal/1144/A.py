n = int(input())
for i in range(n):
    x = input()
    y = set(x)
    d = sorted(x)
    if len(y) == len(x) and ord(d[-1]) - ord(d[0]) == len(x) - 1:
        print('Yes')
    else:
        print('No')