t = int(input())
for i in range(t):
    a = sorted(map(int, input().split()))
    if sum(a) - a[-1] < a[-1]:
        print(sum(a) - a[-1])
    else:
        print(sum(a)//2)