Mod = 1000000007

def f(x):
    a = 0
    b = 2
    for i in range(x):
        b = (a + b) % Mod
        a = (b - a) % Mod
    return b % Mod

n, m = map(int, input().split())
print((f(n) + f(m) - 2) % Mod)