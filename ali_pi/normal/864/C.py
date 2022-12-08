def impossible():
 print(-1)
 exit()
dest, cap, station, journey = map(int, raw_input().strip().split())
left, right = 2 * station, 2*(dest-station)
if journey == 1 and (cap < station or cap < dest-station):
 impossible()
if journey == 2 and (cap < station or cap < right):
 impossible()
if journey >= 3 and (cap < left or cap < right):
 impossible()
time= 0
consume = station
for i in range(journey-1):
 go = left if (i&1) else right
 if consume + go > cap:
  time += 1
  consume = go
 else:
  consume += go
if ((journey & 1) == 0 and consume + station > cap) or ((journey & 1) and (consume + dest - station > cap)):
 print(time+1)
else:
 print(time)