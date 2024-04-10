n = int(input())
b = list(map(int, input().split()))
a = sorted([[x, i] for i, x in enumerate(b)])
s = sum(b)
ans  = []
for i in range(n):
    mx = a[n-1][0]
    if i == a[n-1][1]:
        mx = a[n-2][0]
    if s - b[i] - mx == mx:
        ans.append(i+1)
print(len(ans))
print(' '.join(map(str, ans)))