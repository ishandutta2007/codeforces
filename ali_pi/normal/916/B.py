n, k = map(int,raw_input().split())
cnt = [0] * 200010
ans = ''
for i in range(64):
  if (n >> i)&1:
    k -= 1
    cnt[i] = 1;
if k < 0:
  print("No")
else:
  print("Yes")
  for i in range(64, -64, -1):
    if k >= cnt[i]:
      cnt[i - 1] += cnt[i] * 2
      k -= cnt[i]
      cnt[i] = 0
    else: break
  for i in range(-64, 64):
    if cnt[i]:
      while k:
        cnt[i] -= 1
        cnt[i - 1] += 2 
        i -= 1
        k-= 1
      break
  for i in range(64, -100010, -1): ans += (str(i) + ' ') * cnt[i] 
  print(ans)