n = int(raw_input())

nums = tuple(int(i) for i in raw_input().split())

even = [x for x in nums if x % 2 == 0]
odd = [x for x in nums if x % 2 == 1]

if len(even) == 1:
  print nums.index(even[0]) + 1
else:
  print nums.index(odd[0]) + 1