R=lambda:map(int,raw_input().split())
n,m=R()
print(((n+1)//2*'01')[:n])