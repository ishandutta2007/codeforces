t = int(input())
for i in range(t):
    n = int(input())
    a = input()
    ans = 0
    for j in range(n):
        if abs(ord(a[j]) - ord(a[n-j-1])) > 2 or ord(a[j]) % 2 != ord(a[n-j-1]) % 2:
            ans += 1
    if ans:
        print('NO')
    else:
        print('YES')