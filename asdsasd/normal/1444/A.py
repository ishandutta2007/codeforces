import sys
input = sys.stdin.readline

def div(n):
    lst = []
    for i in range(2, int(n ** 0.5 + 1)):
        if n % i == 0:
            cnt = 0
            while n % i == 0:
                cnt += 1
                n //= i
            lst.append((i, cnt))
    if n != 1:
        lst.append((n, 1))
    return lst

def main():
    p, q = map(int, input().split())
    if p % q != 0:
        print(p)
        return
    ans = 10 ** 20
    lst = div(q)
    pp = p
    for i, cnt in lst:
        tmp = i ** cnt
        cnt2 = 0
        while p % tmp == 0:
            p //= i
            cnt2 += 1
        ans = min(ans, i ** cnt2)
    print(pp // ans)

for _ in range(int(input())):
    main()