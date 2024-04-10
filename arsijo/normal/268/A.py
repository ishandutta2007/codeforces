A = []
B = []
n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)
ans = 0
for i in range(n):
    for j in range(n):
        if A[i] == B[j]:
            ans += 1
print(ans)