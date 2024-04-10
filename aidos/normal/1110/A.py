b, k = map(int, input().split())
a = map(int, input().split())
ans = 0
for i in a:
    ans = (ans * b + i) % 2
if ans == 0:
    print("even")
else:
    print("odd")