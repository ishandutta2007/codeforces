t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    print(''.join([chr(ord('a') + j % k) for j in range(n)]))