import sys 

arr = map(int, sys.stdin.readline().split())

a = arr[0]
b = arr[1]
c = arr[2]

print min(a + b + c, 2 * min(a + b, a + c, b + c))