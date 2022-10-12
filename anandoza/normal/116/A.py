n = int(raw_input())
total = 0
answer = 0
for i in range(n):
  a, b = tuple(int(i)-1 for i in raw_input().split(" "))
  total += b - a
  answer = max(total, answer)

print answer