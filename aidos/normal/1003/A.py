n = int(input())
a = map(int, input().split())
b = [0] * 110

for x in a:
    b[x]+=1
print(max(b))