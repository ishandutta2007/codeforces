n = int(raw_input())
gifts = dict(zip(tuple(int(i) for i in raw_input().split()), range(1, n+1)))
print " ".join(str(gifts[i]) for i in range(1, n+1))