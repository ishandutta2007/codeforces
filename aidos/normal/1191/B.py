a = sorted(input().split())
ans = 2
for i in range(3):
    for j in range(i+1, 3):
        if a[i] == a[j]:
            ans = 1
        elif a[i][1] == a[j][1] and abs(int(a[i][0])-int(a[j][0])) < 3:
            ans = 1

if a[0] == a[2]:
    ans = 0
if a[0][1] == a[1][1] and a[1][1] == a[2][1] and int(a[0][0]) == int(a[1][0]) - 1 and int(a[1][0]) == int(a[2][0])-1:
    ans = 0
print(ans)