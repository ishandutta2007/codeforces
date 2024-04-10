N = int(input())
i = 2
sol = 1
while i * i <= N:
    if N % i == 0:
        sol *= i
        while N % i == 0:
            N //= i
    i += 1
print(sol * N)