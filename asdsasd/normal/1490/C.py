import sys
input = sys.stdin.readline

se = set()
for i in range(1, 10010):
    se.add(i ** 3)

def main():
    n = int(input())
    for s in se:
        if n - s in se:
            print("YES")
            return
    print("NO")
    
for _ in range(int(input())):
    main()