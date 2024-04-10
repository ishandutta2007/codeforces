for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    ans = True
    for i in range(1, n):
        if a[i] - a[i-1] > 1:
            ans = False
            break
    if ans:
        print("YES")
    else:
        print("NO")