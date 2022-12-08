from collections import *
n = input()
s = raw_input()
b = [int (i) for i in raw_input().split(' ')]
n = n
cnt = defaultdict(int)
multiples = []
biggest = 'a'
ans = 0
for i in range(n//2):
    if(s[i] == s[n-i-1]):
        multiples.append(i)
        cnt[s[i]] += 1
        ans += max(b[i],b[n-i-1])
    else:
        ans += b[i] + b[n-i-1]

for i in range(26):
    if(cnt[chr(ord('a')+i)] > cnt[biggest]):
        biggest = chr(ord('a')+i)
more = max(max(cnt.values())*2-sum(cnt.values()),0)
takes = []
for i in range(n//2):
    if(s[i] != s[n-i-1] and s[i] != biggest and s[n-i-1] != biggest):
        takes.append(min(b[i],b[n-i-1]))
takes = sorted(takes)[:more]
pen = sum(takes)
print(ans-pen)