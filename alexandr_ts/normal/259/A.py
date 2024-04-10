a,er = [list(map(str,raw_input().split()))for i in range(8)],0
for i in range(8):
    for j in range(7):
        if a[i][0][j]==a[i][0][j+1]:
            er = 1
if er == 1:
    print('NO')
else:
    print('YES')