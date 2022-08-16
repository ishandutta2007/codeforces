d = dict()
def prob(w,b):
	if(w == 0 or b < 0):
		return 0
	if(b == 0):
		return 1
	if (b,w) in d:
		return d[(b,w)]
	ans1 = w/(w+b)
	if(b == 1):
		ans2 = 0
	else:
		ans2 = b/(w+b)*(b-1)/(w+b-1)*(prob(w-1,b-2)*w/(b+w-2)+prob(w,b-3)*(b-2)/(b+w-2))
	d[(b,w)] = ans1+ans2
	return ans1+ans2
w,b = map(int,input().split())
print(prob(w,b))