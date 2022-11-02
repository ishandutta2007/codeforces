n = int(input())
a = list(map(int, input().split()))
print(max((2 * sum(a)+n)//n, max(a)))