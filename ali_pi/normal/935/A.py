n = input()
print(sum(n%i == 0 for i in range(1,n)))