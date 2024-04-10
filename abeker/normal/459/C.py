load = [int(i) for i in input().split()]

n = load[0]
k = load[1]
d = load[2]

p = 1
for i in range(d):
    p *= k
    if p >= n:
        break

if n > p:
    print(-1)
else:
    nums = [i for i in range(n)]
    for i in range(d):
        buff = ""
        for j in range(n):
            buff += str(nums[j] % k + 1) + ' '
            nums[j] //= k
        print(buff)