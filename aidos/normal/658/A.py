def get(p, t, n, c):
    x = 0
    ans = 0
    for i in range(n):
        x += t[i]
        ans += max(0, p[i] - c * x)
    return ans
    
n, c = map(int, input().split())
p = list(map(int, input().split()))
t = list(map(int, input().split()))
a = get(p, t, n, c)
b = get(p[::-1], t[::-1], n, c)
if a > b:
    print('Limak')
elif a == b:
    print('Tie')
else:
    print('Radewoosh')