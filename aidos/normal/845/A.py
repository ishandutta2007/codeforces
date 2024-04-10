n = int(input())

a = sorted(list(map(int, input().split())))

if a[n] > a[n-1]:
    print("YES")
else:
    print("NO")