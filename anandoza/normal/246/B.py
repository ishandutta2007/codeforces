n = int(raw_input())
nums = tuple(int(i) for i in raw_input().split(" "))

if sum(nums) % n == 0:
  print n
else:
  print n-1