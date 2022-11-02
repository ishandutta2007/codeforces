x, y, z = map(int, input().split())
a, b, c = map(int, input().split())

if a >= x and a + b >= y+x and a + b + c >= x + y + z:
    print("YES")
else:
    print("NO")