import math

n = int(raw_input())

groups = tuple(int(i) for i in raw_input().strip().split(" "))
count = dict()
for i in range(1,5):
  count[i] = groups.count(i)

answer = 0
answer += count[4]
answer += count[2] / 2
count[2] = count[2] % 2
answer += count[3]
count[1] -= count[3]
count[1] -= count[2] * 2
answer += count[2]
answer += max(0, math.ceil(float(count[1]) / 4))

print int(answer)