t = int(input())
for _ in range(t):
    a = sorted(input())
    b = list(input())
    ans = 'NO'
    n = len(a)
    m = len(b)
    for i in range(m-n+1):
        if a == sorted(b[i:i+n]):
            ans = 'YES'
    print(ans)