import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    max_num = 0
    min_num = 200
    for i, a in enumerate(alst):
        if a > max_num:
            max_num = a
            max_pos = i
        if a <= min_num:
            min_num = a
            min_pos = i
    ans = max_pos + (n - min_pos - 1)
    if max_pos > min_pos:
        ans -= 1
    print(ans)
    
    
main()