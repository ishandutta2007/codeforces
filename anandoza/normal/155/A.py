n = int(raw_input())

scores = (tuple(int(i) for i in raw_input().split()))

small = scores[0]
large = scores[0]
answer = 0

for s in scores[1:]:
  if s < small:
    answer += 1
    small = s
  if s > large:
    answer += 1
    large = s

print answer