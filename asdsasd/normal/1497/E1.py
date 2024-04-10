import sys
input = sys.stdin.readline

max_ = 10 ** 4
tf = [True] * (max_ + 1)
tf[0] = False
tf[1] = False
for i in range(2, int((max_ + 1) ** 0.5 + 1)):
    if not tf[i]: continue
    for j in range(i * i, max_ + 1, i):
        tf[j] = False
primes = []
for i in range(2, max_ + 1):
    if tf[i]:
        primes.append(i)

def main():
    n, k = map(int, input().split())
    alst = list(map(int, input().split()))
    ans = 1
    se = set()
    for a in alst:
        for p in primes:
            pp = p * p
            if pp > a:
                break
            while a % pp == 0:
                a //= pp
        if a in se:
            ans += 1
            se = set()
        se.add(a)
    print(ans)
    
    
for _ in range(int(input())):
    main()