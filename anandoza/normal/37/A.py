from collections import Counter

n = int(raw_input())
towers = tuple(int(i) for i in raw_input().split())
print Counter(towers).most_common()[0][1], len(set(towers))