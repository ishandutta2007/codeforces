n = int(input())
m = int(input())

if n > 30:
  n = 30

print(m % (2**n))