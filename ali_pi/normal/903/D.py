n = input()
a = map(int, raw_input().split())
mp = dict()
ans = 0
sum = 0
for i in range(n):
    ans = ans + a[i] * i - sum + mp.get(a[i] + 1, 0) - mp.get(a[i] - 1, 0) 
    sum = sum + a[i]
    mp[a[i]] = mp.get(a[i] , 0) + 1
print (ans)