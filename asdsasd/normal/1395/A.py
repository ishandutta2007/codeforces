import sys
input = sys.stdin.buffer.readline

def main():
    r, g, b, w = map(int, input().split())
    cnt = 0
    for num in [r, g, b, w]:
        if num % 2 == 1:
            cnt += 1
    if cnt <= 1:
        print("Yes")
        return
    if r == 0 or g == 0 or b == 0:
        print("No")
        return
    if cnt == 2:
        print("No")
    else:
        print("Yes")
    

t = int(input())    
for _ in range(t):
    main()