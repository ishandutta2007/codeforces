n, k = map(int, input().split())
s = list(input())
if s[0] != '1' and k > 0 and n > 1:
    s[0] = '1'
    k -= 1
elif s[0] != '0' and k > 0 and n == 1:
    s[0] = '0'
for i in range(1, n):
    if s[i] != '0' and k > 0:
        s[i] = '0'
        k -= 1
print(''.join(s))