x = raw_input().split()
n = int(x[0])
k = int(x[1])
print 3*n + min(n-k , k - 1 )