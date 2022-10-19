import sys
input = sys.stdin.readline
from collections import deque

def main():
    n = int(input())
    A = list(map(int, input().split()))
    cnt = {}
    for a in A:
        cnt[a] = cnt.get(a, 0) + 1
    if any(c % 2 == 1 for c in cnt.values()):
        print(-1)
        return
    B = []
    goal = []
    query = []
    queue = deque(A)
    while queue:
        a = queue.popleft()
        lst = [a]
        while queue[0] != a:
            lst.append(queue.popleft())
        queue.popleft()
        
        B.append(a)
        p = len(B) + len(lst)
        for l in lst[1:]:
            B.append(l)
            queue.appendleft(l)
            query.append((p, l))
            p += 1
        B += lst
        goal.append(len(lst) * 2)
    print(len(query))
    for row in query:
        print(*row)
    print(len(goal))
    print(*goal)
    
    
    
        
    
for _ in range(int(input())):
    main()