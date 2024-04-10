g = [0, 1, 2, 0, 2, 1, 0]
a=list(map(int, input().split()))
ans = 0
for i in range(7):
    b = a.copy()
    cnt = 0
    good = 1
    for j in range(i, 7):
        if b[g[j]] > 0:
            b[g[j]] -= 1
            cnt+=1
        else:
            good = 0
            break
    if good:
        x = min(b[0]//3, b[1]//2, b[2]//2)
        cnt += x * 7
        b[0] -= 3 * x
        b[1] -= 2 * x
        b[2] -= 2 * x
        for j in range(7):
            if b[g[j]] > 0:
                cnt+=1
                b[g[j]] -= 1
            else:
                break
    ans =max(ans, cnt)
print(ans)