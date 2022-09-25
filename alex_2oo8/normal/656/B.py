n = int(input())
M = list(map(int, input().split()))
R = list(map(int, input().split()))
N = 720720
P = 0
for x in range(N):
    if any(x % M[i] == R[i] for i in range(n)):
        P += 1

print(P * 1.0 / N)