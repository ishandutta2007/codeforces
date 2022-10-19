def reverse(t):
    ans = ''
    for i in t:
        ans = i + ans
    return ans

s = input()
t = input()
print('YES' if s == reverse(t) else 'NO')