a = []

for i in range(8):
    a.append(input())

ans = 100, 'C'

for i in range(8):
    for j in range(8):
        if a[i][j] == 'W':
            st = True
            for k in range(i):
                if a[k][j] == 'B':
                    st = False
            if st:
                if i < ans[0]:
                    ans = i, 'A'

for i in range(8):
    for j in range(8):
        if a[i][j] == 'B':
            st = True
            for k in range(i + 1, 8):
                if a[k][j] == 'W':
                    st = False
            if st:
                if 8 - i - 1 < ans[0]:
                    ans = 8 - i - 1, 'B'

print(ans[1])