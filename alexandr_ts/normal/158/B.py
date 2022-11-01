n=int(raw_input())
a=map(map(int,raw_input().split()).count,range(1,5))
print a[3] + a[2] + (a[1] * 2 + max(a[0]-a[2], 0) + 3)/ 4