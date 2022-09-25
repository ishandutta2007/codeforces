m, k = [int(x) for x in input().split()]

seen = 0
users = set()
friendsof = {}
for i in range(m):
	a, b = [int(x) for x in input().split()]
	users.add(a)
	users.add(b)
	if a in friendsof:
		friendsof[a].add(b)
	else:
		friendsof[a] = set((b,))
	if b in friendsof:
		friendsof[b].add(a)
	else:
		friendsof[b] = set((a,))

users_sorted = list(users)
users_sorted.sort()

for u in users_sorted:
	possible = []
	this_friends = friendsof[u]
	
	for v in users_sorted:
		if v in this_friends: continue
		if v == u: continue
		common = friendsof[v].intersection(this_friends)
		
		if len(common) * 100 >= k * len(this_friends):
			possible.append(v)
	
	print('{}:'.format(u), len(possible), *possible)