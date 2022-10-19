import sys
input = sys.stdin.readline

def main():
    for _ in range(int(input())):
        n, m = map(int, input().split())
        dic = [[] for _ in range(n * m)]
        for _ in range(n):
            lst = list(map(int, input().split()))
            dic[lst[0] - 1] = lst
        for _ in range(m):
            lst = list(map(int, input().split()))
            num = lst[0] - 1
            if dic[num] == []:
                continue
            for num in lst:
                print(*dic[num - 1])
                
main()