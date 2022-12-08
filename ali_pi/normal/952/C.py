n=input()
a=list(map(int,raw_input().split()))
print('NO' if any(abs(a[i]-a[i+1])>1 for i in range(n-1))else 'YES')