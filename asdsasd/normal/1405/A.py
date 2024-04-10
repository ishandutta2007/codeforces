def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        plst = list(map(int, input().split()))
        print(*plst[::-1])
    
main()