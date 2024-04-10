z=1<<24
for n in[*open(0)][1:]:
	x=0
	for i in range(int(n)-3):x^=i;print(i)
	print(z,2*z,3*z^x)