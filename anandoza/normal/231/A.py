n = int(raw_input())

answer = 0
for i in range(n):
  sure = tuple(int(i) for i in raw_input().split(" "))
  if sum(sure) >= 2:
    answer += 1

print answer