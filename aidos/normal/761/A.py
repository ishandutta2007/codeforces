n, m = map(int, input().split())
if abs(n-m) <= 1 and max(n, m) > 0:
    print("YES")
else:
    print("NO")