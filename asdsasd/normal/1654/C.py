import sys
input = sys.stdin.readline
from heapq import *

def main():
    n = int(input())
    A = list(map(int, input().split()))
    if n == 1:
        print("YES")
        return
    tot = sum(A)
    cnt = {}
    for a in A:
        cnt[a] = cnt.get(a, 0) + 1
    stack = [tot]
    
    for _ in range(n - 1):
        x = stack.pop()
        y = x // 2
        z = x - y
        if cnt.get(y, 0) > 0:
            cnt[y] -= 1
        else:
            stack.append(y)
        if cnt.get(z, 0) > 0:
            cnt[z] -= 1
        else:
            stack.append(z)
    if stack:
        print("NO")
    else:
        print("YES")
        
            
        
        
    
    
    
    
for _ in range(int(input())):
    main()