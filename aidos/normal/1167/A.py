t = int(input())
for i in range(t):
    n = int(input())
    s = input()
    i = 0
    while i < n and s[i] != '8':
        i+=1
    if (n-i)>=11:
        print('YES')
    else:
        print('NO')