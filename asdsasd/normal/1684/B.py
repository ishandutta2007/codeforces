import sys
input = sys.stdin.readline

def solve():
    a, b, c = map(int, input().split())
    z = c
    y = b
    x = a + b * c
    print(x, y, z)
    

    
    
for _ in range(int(input())):
    solve()