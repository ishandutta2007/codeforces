n, a, b = map(int, input().split())
cnt = 0
a-=1
b-=1
while a != b:
    a//=2
    b//=2
    n//=2
    cnt += 1
if n == 1:
    print("Final!")
else:
    print(cnt)