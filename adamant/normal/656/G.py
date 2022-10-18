F,I,K=map(int,input().split(" "))
f=[v for i in range(F) for v in input()]
print(sum(K<=sum(f[i+I*j]=='Y' for j in range(F)) for i in range(I)))
#kitten