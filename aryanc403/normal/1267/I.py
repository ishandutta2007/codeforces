def main():
    def solve():
        n = int(input())
        
        arr = [[0] * (2 * n) for _ in range(2 * n)]
        
        def query(a, b):
            if not arr[a][b]:
                print("? {} {}".format(a + 1, b + 1), flush=True)
                tmp = input()
                if tmp == '<':
                    arr[a][b] = -1
                    arr[b][a] = 1
                else:
                    arr[a][b] = 1
                    arr[b][a] = -1
            return arr[a][b]
        
        def reduce(*arr):
            winners = []
            losers = []
            for i in range(3):
                q = query(arr[2 * i], arr[2 * i + 1])
                if q == -1:
                    losers.append(arr[2 * i])
                    winners.append(arr[2 * i + 1])
                else:
                    losers.append(arr[2 * i + 1])
                    winners.append(arr[2 * i])
            wins = [0] * 3
            for i in range(3):
                for j in range(i + 1, 3):
                    q = query(losers[i], losers[j])
                    if q == 1:
                        wins[i] += 1
                    else:
                        wins[j] += 1
            d = -1
            for i in range(3):
                if wins[i] == 2:
                    winners[0], winners[i] = winners[i], winners[0]
                    d = losers[i]
            a, b, c = winners
            return a, d, b, c
        
        if n == 3:
            a, d, b, c = reduce(*range(6))
            if query(b, c) == 1:
                query(d, c)
            else:
                query(d, b)
        else:
            a, d, b, c = reduce(*range(6))
            for i in range(6, 2 * n, 2):
                a, d, b, c = reduce(a, d, b, i, c, i + 1)
            if query(b, c) == -1:
                b, c = c, b
            for i in range(2 * n):
                if i == a or i == b:
                    continue
                for j in range(2 * n):
                    if j == i or j == a or j == b:
                        continue
                    query(i, j)
        
        print("!", flush=True)
    
    for _ in range(int(input())):
        solve()
    
    return 0

main()