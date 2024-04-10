n = int(input())
t = 0
t+=n//100
n%=100
t+=n//20
n%=20
t+=n//10
n%=10
t+=n//5
n%=5
t+=n
print(t)