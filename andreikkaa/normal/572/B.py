n, s = map(int, input().split())

buy = {}
sell = {}

for i in range(n):
    a = input().split()
    a[1] = int(a[1])
    a[2] = int(a[2])
    
    if a[0] == "B":
        buy[a[1]] = buy.get(a[1], 0) + a[2]
    else:
        sell[a[1]] = sell.get(a[1], 0) + a[2]

buy = list(buy.items())
sell = list(sell.items())

sell.sort()
buy.sort()

sell = sell[:s]
buy = buy[-s:]

sell.reverse()
buy.reverse()

for i in sell:
	print("S", i[0], i[1])

for i in buy:
	print("B", i[0], i[1])