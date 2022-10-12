from math import ceil

n, d = tuple(int(i) for i in raw_input().split(" "))
nums = tuple(int(i) for i in raw_input().split(" "))

answer = 0
c = nums[0] + 1
for k in nums[1:]:
  m = max(0, int(ceil(float(c - k) / d)))
  c = k + m * d + 1
  answer += m

print answer