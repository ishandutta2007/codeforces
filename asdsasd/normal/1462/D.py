import sys
input = sys.stdin.readline

def divisor_lst(n):
    lst = []
    for i in range(1, int(n ** 0.5 + 1)):
        if n % i == 0:
            lst.append(i)
            lst.append(n // i)
            if i == n // i:
                lst.pop()
    return lst
    
def main():
    n = int(input())
    alst = list(map(int, input().split()))
    tot = sum(alst)
    lst = divisor_lst(tot)
    lst.sort()
    ans = n - 1
    
    for t in lst:
        total = 0
        tmp = 0
        flg = True
        for a in alst:
            total += a
            if total > t:
                flg = False
                break
            elif total == t:
                total = 0
        if flg:
            ans = min(ans, n - tot // t)
    print(ans)
    
    
    
for _ in range(int(input())):
    main()