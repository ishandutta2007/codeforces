N,*A=map(int,open(0).read().split())
T=[*zip(A,A[4:]+A[3:4])]
print(sum(max(0,a+b-N)for a,b in T),sum(map(min,T)))