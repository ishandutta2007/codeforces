def solve():
    n = int(input())
    s = input()
    total = 0
    ans = [0 for _ in range(n)]
    min_k = 0
    max_k = 0
    for ss in s:
        if ss == "1":
            total += 1
            max_k = max(max_k, total)
        else:
            total -= 1
            min_k = min(min_k, total)
    k = max_k - min_k
    print(k)
    plus = abs(min_k)
    total = 0
    for i, ss in enumerate(s):
        if ss == "1":
            total += 1
            ans[i] = total + plus
        else:
            ans[i] = total + plus
            total -= 1
    print(*ans)
            

t = int(input())
for _ in range(t):
    solve()