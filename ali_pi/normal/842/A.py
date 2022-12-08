l,r,x,y,k=map(int,raw_input().split())
print('NO'if max((l+k-1)//k,x)>min(r//k,y) else'YES')