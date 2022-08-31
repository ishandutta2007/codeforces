n = int(input())
a = list(map(int,input().split()))
sum = sum(a)
max = max(a)
if(max <= (sum - max) and sum%2 == 0):
  print("YES")
else:
  print("NO")