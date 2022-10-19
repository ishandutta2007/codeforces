import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    A = [(a, i) for i, a in enumerate(A, 1)]
    A.sort(key = lambda x:-x[0])
    I = [0]
    ans = 0
    for a, i in A[:k]:
        ans += a
        I.append(i)
    I.sort()
    I.pop()
    I.append(n)
    print(ans)
    print(*(I[i] - I[i - 1] for i in range(1, k + 1)))
    
    
for _ in range(1):
    main()