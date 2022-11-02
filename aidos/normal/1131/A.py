w1, h1, w2, h2 = map(int, input().split())
w1 = max(w1, w2)
h1 += h2
print(2*(w1+h1) + 4)