import itertools
def check(num1, num2):
    for i, j in zip(num1, num2):
        if i == j:
            return True
    return False

t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    ss = set()
    for i in range(n):
        ss.add(s[i:i+n])
    for nn in itertools.product("01", repeat=n):
        n2 = "".join(nn)
        for num in ss:
            if check(n2, num):
                continue
            break
        else:
            print(n2)
            break