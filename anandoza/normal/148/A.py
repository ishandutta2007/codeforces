k = int(raw_input())
l = int(raw_input())
m = int(raw_input())
n = int(raw_input())
d = int(raw_input())

print len([x for x in range(1, d+1) if (x%k==0 or x%l==0 or x%m==0 or x%n==0)])