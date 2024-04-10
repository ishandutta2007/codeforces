from heapq import*
n, m = [int(i) for i in raw_input().split()]
food = 0
tummy = []
dish = [ -int(i) for i in raw_input().split()]
for i in range(1, min(m, n+1)):
    while tummy and -tummy[0] >= m- i:
        heappop(tummy)
    if max(-dish[i-1], i) < m:
        heappush(tummy, dish[i-1] + i)
    food = max(len(tummy), food)
print(food)