t, s, x = map(int, input().split())

if t % s == x % s and t <= x:
    print("YES")
elif (t+1) % s == x % s and t+1<x:
    print("YES")
else:
    print("NO")