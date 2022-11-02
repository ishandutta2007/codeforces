t = int(input())
for i in range(t):
    a = list(map(int, input().split()))
    if sum(a) % 3 != 0 or max(a[:3]) > sum(a)//3:
        print("NO")
    else:
        print("YES")