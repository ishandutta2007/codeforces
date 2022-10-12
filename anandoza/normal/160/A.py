n = int(raw_input())
coins = [int(i) for i in raw_input().split()]
coins.sort()
half = sum(coins) / 2

answer = 0
total = 0
for c in reversed(coins):
  answer += 1
  total += c
  if total > half:
    break

print answer