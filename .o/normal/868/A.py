a=input()
n=int(input())
s=[input() for i in range(n)]
def go():
    print("YES")
    exit()
    
for x in s:
    if x == a: go()
    for y in s:
        if a in (x + y): go()

print("NO")