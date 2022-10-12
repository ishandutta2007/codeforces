n = int(raw_input())

values = []
k = 1
answer = 0
for i in range(n):
  value, bonus = (tuple(int(i) for i in raw_input().split()))
  if bonus > 0:
    k += bonus - 1
    answer += value
  else:
    values.append(value)

values.sort()
answer += sum(values[-k:])

print answer