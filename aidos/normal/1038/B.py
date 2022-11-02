n = int(input())
sum = n * (n + 1)//2

if n <= 2:
    print('No')
else:
    x = (n+1)//2
    if n % 2 == 0:
        x = n//2
    print('Yes')
    print(1, x)
    print(n-1, end = ' ')
    for i in range(1, n + 1):
        if i != x:
            print(i, end = ' ')