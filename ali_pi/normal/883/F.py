n=input()
d=[]
for i in xrange(n):
	s=raw_input()
	s=s.replace("u","oo")
	while s.count("kh")!=0:
		s=s.replace("kh","h")
	if not s in d:
		d.append(s)
print len(d)