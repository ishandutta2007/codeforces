n = int(raw_input())

cur = ""
answer = 0

for i in range(n):
  prev = cur
  cur = raw_input()
  if cur != prev:
    count = 0
  count += 1
  answer = max(answer, count)

print answer