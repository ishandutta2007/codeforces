s = input()
k = int(input())

a = list(map(int, input().split()))

plus = max(a)
itog = 0

for i in range(1, len(s) + 1):
    itog += a[ord(s[i - 1]) - ord('a')] * i

for i in range(len(s) + 1, len(s) + 1 + k):
    itog += plus * i
    
print(itog)