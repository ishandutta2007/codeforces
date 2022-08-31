n = int(input())
i = 2
while(i < n):
    while n%i == 0:
        n //= i
        print(i,end="")
    i += 1
if n > 1: print(n,end="")