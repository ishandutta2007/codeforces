x, k = map(int, input().split(" "))
M = 10 ** 9 + 7

def get(x, k):
    if k == 0:
        return x
    else:
        a = pow(2, k - 1, M)
        b = (2 * x - 1) * pow(2, k, M) + 1
        c = pow(pow(2, k, M), M - 2, M)
        ans = a * b * c % M
        return ans

if k == 0 or x == 0:
    print(x * 2 % M)
else:
    ans = get(x, k) * 2 % M
    print(ans)