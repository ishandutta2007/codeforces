L=sorted(list(map(int,input().split())))
print(min(L[0]+L[1],(L[0]+L[1]+L[2])//3))