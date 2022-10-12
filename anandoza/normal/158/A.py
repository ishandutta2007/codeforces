n, k = tuple(int(i) for i in raw_input().strip().split(" "))
scores = tuple(int(i) for i in raw_input().strip().split(" "))

cutoff = scores[k-1]

print sum(1 for x in scores if x >= cutoff and x > 0)