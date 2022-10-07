import queue;

q = queue.PriorityQueue();



k, n = map(int, input().split())
a = sorted(list(map(int, input().split())))

q = queue.PriorityQueue();
for x in a:
    q.put(-x)

mx = 0;
mn = 0;
for i in range(0, k):
    x = -q.get();
    #print(q.qsize())
    mx += x;
    q.put(-(x - 1));

cur = 0;
for i in range(0, k):
    if a[cur] == 0:
        cur += 1;
    mn += a[cur];
    a[cur] -= 1;

     

print(mx, mn);