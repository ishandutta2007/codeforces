k=lambda:map(int,raw_input().split())
_,x=k()
print(x+sum((i==x)-(i<x)for i in k()))