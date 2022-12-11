n = int(raw_input())
nums = list(map(int,raw_input().split()))
for i in range(n/2):
  if i%2==0:
    nums[i],nums[n-i-1] = nums[n-i-1],nums[i]
print " ".join([str(x) for x in nums])