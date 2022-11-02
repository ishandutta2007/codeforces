t = int(input())
for _ in range(t):
    a = input()
    b = input()
    c = input()
    ans='YES'
    for i in range(len(a)):
        if a[i] != c[i] and c[i] != b[i]:
            ans = 'NO'
    print(ans)