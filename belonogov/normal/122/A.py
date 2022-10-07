

def check(x):
    flag = 1
    while x > 0:
        r = x % 10
        flag &= (r == 7 or  r == 4)
        x //= 10
    return flag

n = int(input())

flag = 0

for x in range(2, n + 1):
    #print("-----")
    #print(x)
    #print(n % x == 0)
    #print(check(x));
    flag |= (n % x == 0 and check(x))


print(["NO", "YES"][flag])