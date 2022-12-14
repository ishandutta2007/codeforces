s, k = input(), int(input())

if len(s) % k != 0:
    print("NO")
else:
    l = len(s) // k
    for i in range(0, len(s), l):
        sub = s[i:i + l]
        if sub != sub[::-1]:
            print("NO")
            exit(0)
    print("YES")