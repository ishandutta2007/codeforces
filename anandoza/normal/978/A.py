n = int(raw_input())

nums = tuple(int(i) for i in raw_input().split())

answer = []

for i in range(len(nums)):
    if not nums[i] in nums[i+1:]:
        answer.append(nums[i])
        
print len(answer)
print ' '.join(str(x) for x in answer)