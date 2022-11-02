t = int(input())
for i in range(t):
    n = int(input())
    s = '1' * (n//2 - 1)
    if n % 2 == 1:
        s = '7' + s
    else:
        s = '1' + s
    print(s)