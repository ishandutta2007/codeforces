n, m = map(int, input().split())
if n == m:
    print(n*10+8, n*10+9)
elif n+1 == m:
    print(n*10+9, m * 10)
elif n == 9 and m == 1:
    print(9, 10)
else:
    print(-1)