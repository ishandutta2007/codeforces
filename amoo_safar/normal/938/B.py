v = 'aiouey'
n = int(input())
a = list(map(int,input().split()))
fr = 1000000
mi = 0
for i in a:
    mi = max(min(fr-i,i-1),mi)
print(mi)