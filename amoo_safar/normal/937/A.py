n = int(input())
s = set(map(int,input().split()))
if 0 in s:print(max(0,len(s)-1))
else:print(len(s))