def main():
 n = int(input())
 a = list(map(int, input().split()))[::-1]
 
 to = n + 2
 t = [0] * to
 
 ans = 0
 for i in a:
  j = i
  while j >= 0:
   ans += t[j]
   j = (j & (j + 1)) - 1
  j = i
  while j < to:
   t[j] += 1
   j |= (j + 1)
 print(ans)


t = int(input())
for i in range(t):
 main()