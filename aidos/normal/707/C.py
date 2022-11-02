n = int(input())
if n == 1 or n == 2:
    print(-1)
elif n % 2 == 1:
    x = n * n
    y = 1
    print((x+y)//2, (x-y)//2)
else:
    x = n * n//2
    y = 2
    print((x+y)//2, (x-y)//2)