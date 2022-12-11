import sys
n,m = map(int,raw_input().split())
temp = n-1
hrs = 1
while temp/7:
  hrs += 1
  temp /= 7
temp = m-1
mins = 1
while temp/7:
  mins += 1
  temp /= 7
if mins+hrs >= 8:
  print 0
  sys.exit()
ans = 0
nums = [0 for x in range(hrs)]
nums2 = [0 for x in range(mins)]
for i in range(n*m):
  cur = i
  temp = cur/m
  cur %= m
  for j in range(hrs-1,-1,-1):
    nums[j] = temp%7
    temp /= 7
  for j in range(mins-1,-1,-1):
    nums2[j] = cur%7
    cur /= 7
  if len(set(nums+nums2))==hrs+mins:
    ans += 1
print ans