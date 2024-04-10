n = int(input())
a = map(int, input().split())
b = map(int, input().split())
if sum(a) >= sum(b):
    print('Yes')
else:
    print('No')