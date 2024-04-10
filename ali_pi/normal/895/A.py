n=input()
a=list(map(int,raw_input().split()))
print(2*min(abs(180-sum(a[l:r])) for l in range(n) for r in range(l,n)))