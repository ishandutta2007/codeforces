n, k = map(int, input().split())
a = [0] * k
b = input()
for i in b:
    a[ord(i) - ord('A')] += 1
print(min(a) * k)