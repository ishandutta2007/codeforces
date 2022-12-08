def main():
    n, d, k = list(map(int, raw_input().split()))
    if n == 2 and d == 1 and k == 1:
        print("YES")
        print "1 2"
        return 0
    if n == d + 1 and k - 1:
        print("YES")
        for i in range(1, d + 1):
            print i, i + 1
        return 0
    if  n < d +1 or k <= 2 or d == 1:
        print("NO")
        return 0
    if d % 2 == 0:
        if n * (k - 2) > -2 + k * (k - 1) ** (d // 2):
            print("NO")
            return 0
        print("YES")
        for i in range(1, d + 1):
            print i, i + 1
        nodes = d + 1
        leaves = [1 + d // 2]
        dev = 0
        while True:
            new_leaves = []
            for i in leaves:
                for j in range(k - 1 - (i <= d + 1)):
                    nodes += 1
                    print i, nodes
                    new_leaves.append(nodes)
                    if nodes == n:
                        return 0
            dev += 1
            leaves = new_leaves + [1 - dev + d // 2, 1 + dev + d // 2]

    else:
        if n * (k - 2) > -2 + k * (k - 1) ** (d // 2) + (k - 2) * (k - 1) ** (d // 2):
            print("NO")
            return 0
        print("YES")
        for i in range(1, d + 1):
            print i, i + 1
        nodes = d + 1
        leaves = [1 + d // 2, 2 + d // 2]
        dev = 0
        while True:
            new_leaves = []
            for i in leaves:
                for j in range(k - 1 - (i <= d + 1)):
                    nodes += 1
                    print i, nodes
                    new_leaves.append(nodes)
                    if nodes == n:
                        return 0
            dev += 1
            leaves = new_leaves + [1 - dev + d // 2, 2 + dev + d // 2]
main()