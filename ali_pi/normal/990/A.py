n,m,a,b=map(int,raw_input().split())
print(min(n%m*b,(m-n%m)*a))