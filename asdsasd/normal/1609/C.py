import sys
input = sys.stdin.readline

N = 2000000
isprime = [True] * N
isprime[0] = isprime[1] = False
for i in range(2, int(N ** 0.5 + 1)):
    if not isprime[i]:
        continue
    for j in range(i * i, N, i):
        isprime[j] = False


def main():
    n, e = map(int, input().split())
    A = list(map(int, input().split()))
    ans = 0
    for i in range(e):
        lst = []
        for j in range(i, n, e):
            if A[j] == 1:
                if lst and lst[-1] > 0:
                    lst[-1] += 1
                else:
                    lst.append(1)
            elif isprime[A[j]]:
                lst.append(0)
            else:
                lst.append(-1)
        l = len(lst)
        for i in range(l):
            if lst[i] == 0:
                if i > 0: b = max(0, lst[i - 1]) + 1
                else: b = 1
                if i < l - 1: a = max(0, lst[i + 1]) + 1
                else: a = 1
                ans += a * b - 1

    print(ans)
                
            
    
    
for _ in range(int(input())):
    main()