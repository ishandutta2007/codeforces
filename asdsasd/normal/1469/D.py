import sys
input = sys.stdin.readline

def main(n):
    ans = []
    A = [i for i in range(1, n + 1)]
    for i in range(n - 1, 2, -1):
        if i * i <= A[n - 1]:
            ans.append((n, i))
            A[n - 1] = (A[n - 1] + A[i - 1] - 1) // A[i - 1]
        ans.append((i, n))
        A[i - 1] = (A[i - 1] + A[n - 1] - 1) // A[n - 1]
    i = 2
    while A[n - 1] != 1:
        ans.append((n, i))
        A[n - 1] = (A[n - 1] + A[i - 1] - 1) // A[i - 1]
    print(len(ans))
    for row in ans:
        print(*row)
        pass
    
    assert len(ans) <= n + 5
    assert A.count(1) == n - 1
    assert A.count(2) == 1, A
    
for _ in range(int(input())):
    main(int(input()))