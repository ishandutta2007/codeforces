n = int(input())
arr = input()
final = len(arr)
arr = arr.split()
lens = [0 for x in range(n)]
visit = [0 for x in range(n)]
cnt = 0
ans = 0
for i in range(n):
  if visit[i]:
    continue
  lens[cnt] = len(arr[i])
  for j in range(i+1,n):
    if arr[j]==arr[i]:
      arr[j] = cnt
      visit[j] = 1
  arr[i] = cnt
  cnt += 1
for i in range(n):
  for j in range(i,n):
    temp = arr[i:j+1]
    ind = 1
    found = 0
    len2 = j-i+1
    cur = 0
    kmp = [0 for x in range(len2)]
    while ind < len2:
      if temp[ind] == temp[cur]:
        cur += 1
        kmp[ind] = cur
        ind += 1
      else:
        if cur != 0:
          cur -= 1
        else:
          kmp[ind] = 0
          ind += 1
    ind = 0
    cur = 0
    while ind < n:
      if arr[ind] == temp[cur]:
        ind += 1
        cur += 1
      if cur == len2:
        found += 1
        cur = 0
      elif ind < n and temp[cur] != arr[ind]:
        if cur != 0:
          cur = kmp[cur-1]
        else:
          ind += 1
    if found>1:
      res = 0
      for k in temp:
        res += (lens[k]-1)*(found)
      res += (len(temp)-1)*(found)
      ans = max(ans,res)
print(final-ans)