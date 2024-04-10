for tc in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    print(max([l.count(y) for y in range(101)]))