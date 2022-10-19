def main():
    tt = int(input())
    while tt > 0:
        tt -= 1
        n = int(input())
        a = [int(u) for u in input().split()]
        cnt = dict()
        for e in a:
            if e in cnt:
                cnt[e] += 1
            else:
                cnt[e] = 1
        most_common = 0
        for key, val in cnt.items():
            most_common = max(most_common, val)
        if most_common > n / 2:
            print(2 * most_common - n)
        else:
            print(n % 2)


if __name__ == '__main__':
    main()