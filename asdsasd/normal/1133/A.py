import sys
input = sys.stdin.readline

def main():
    h1, m1 = map(int, input().split(":"))
    h2, m2 = map(int, input().split(":"))
    m1 += h1 * 60
    m2 += h2 * 60
    m = (m1 + m2) // 2
    h = m // 60
    m -= h * 60
    print("{:02}:{:02}".format(h, m))
    
for _ in range(1):
    main()