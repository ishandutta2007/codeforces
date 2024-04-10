t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    z = map(int, input().split())
    a = [x&1 for x in z]
    if sum(a) < k or sum(a) % 2 != k % 2:
        print('NO')
        continue
    ans = []
    for i in range(n):
        if len(ans) == k - 1:
            break
        if a[i]:
            ans.append(i+1)
    ans.append(n)
    print('YES')
    print(' '.join(map(str, ans)))