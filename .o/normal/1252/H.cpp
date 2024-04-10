def f(x):return sum(map(int,str(x)))
x=int(input())
while x>=10: x=f(x)
print(x)