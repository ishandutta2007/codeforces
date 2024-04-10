n = int(input())
a = list(map(int, input().split()))
i = 0
while i + 1 < n and a[i] < a[i+1]:
    i += 1
j = n-1
while j > 0 and a[j] < a[j-1]:
    j -= 1
if i > j:
    print('YES')
elif len(set(a[i:j + 1])) == 1:
    print('YES')
else:
    print('NO')