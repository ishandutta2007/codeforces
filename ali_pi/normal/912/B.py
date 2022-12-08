n,k=map(int,raw_input().split())
print(n if k==1 else (1<<len(bin(n))-2)-1)