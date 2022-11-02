l = int(input())
r = int(input())
n = abs(r-l)
x = n//2
y = n - x
print(x * (x+1)//2 + y * (y+1)//2)