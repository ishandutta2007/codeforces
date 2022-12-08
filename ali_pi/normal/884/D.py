n=input()
import heapq
a=[int(i) for i in raw_input().split()]+[[0],[]][n&1]
heapq.heapify(a)
k=0
while len(a)>1:
    s=heapq.heappop(a)+heapq.heappop(a)+heapq.heappop(a)
    k+=s
    heapq.heappush(a,s)
print(k)