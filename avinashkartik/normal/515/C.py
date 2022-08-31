n = int(input())
q = list(input())
a = [[],[],[2],[3],[2,2,3],[5],[3,5],[7],[2,2,2,7],[3,3,2,7]]
l = []
for i in q:
	ind = int(i)
	l.extend(a[ind])
l.sort(reverse = True)
for i in l:
	print(i,end = "")
print()