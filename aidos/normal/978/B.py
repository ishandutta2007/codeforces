n = int(input())
a = input()

i = 0
ans = 0
while i < n:
    j = i
    while i < n and a[i] == 'x':
        i += 1
    if i - j > 2:
        ans += i - j - 2
    i += 1
print(ans)