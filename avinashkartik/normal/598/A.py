t = int(input())
for y in range(t):
    n = int(input())
    s = (n*(n+1))//2
    i = 1
    while(i <= n):
        s -= 2*i
        i *= 2
    print(s)