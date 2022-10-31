n, m = map(int, input().split())
x, k, y = map(int, input().split())

a = list(map(int, input().split()))

where = [0] * n

for i in range(n):
    a[i] -= 1
    where[a[i]] = i

left = [-1]

b = list(map(int, input().split()))

for i in range(m):
    b[i] -= 1
    left.append(where[b[i]])

left.append(n)

ans = 0

for i in range(1, len(left)):
    if left[i - 1] > left[i]:
        print(-1)
        exit(0)
    mx = -1
    mx_idx = 0
    for j in range(max(0, left[i - 1]), min(n, left[i] + 1)):
        if a[j] > mx:
            mx = a[j]
            mx_idx = j
    l = left[i] - left[i - 1] - 1
    if l <= 0:
        continue;
    segments = l // k
    remainder = l % k
    if mx_idx == left[i - 1] or mx_idx == left[i]:
        ans += min(l * y, segments * x + remainder * y)
    else:
        if segments == 0:
            print(-1)
            exit(0)
        else:
            ans += min(x + (l - k) * y, segments * x + remainder * y)

print(ans)