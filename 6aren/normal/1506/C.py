def main():
    tt = int(input())
    while tt > 0:
        tt -= 1
        s = input()
        t = input()
        n = len(s)
        m = len(t)
        ans = -1
        for i in range(min(n, m)):
            for x in range(0, n - i):
                for y in range(0, m - i):
                    if s[x:x+i+1] == t[y:y+i+1]:
                        ans = i
        print(n + m - 2 * (ans + 1))

if __name__ == '__main__':
    main()