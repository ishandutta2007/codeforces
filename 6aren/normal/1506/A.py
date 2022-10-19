def main():
    t = int(input())
    while t > 0:
        t -= 1
        n, m, x = [int(u) for u in input().split()]
        xx, yy = ((x - 1) % n, (x - 1) // n)
        print(xx * m + yy + 1)

if __name__ == '__main__':
    main()