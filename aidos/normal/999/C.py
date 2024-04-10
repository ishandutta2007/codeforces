n, k = map(int, input().split())
s = list(input())
a = sorted([[x, i] for i, x in enumerate(s)])

for i in range(k):
    s[a[i][1]] = ''
print(''.join(s))