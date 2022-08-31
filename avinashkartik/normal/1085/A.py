t = input()
mid = (len(t)-1)//2
s = ""
i,j = mid,mid+1
while(i >= 0 or j < len(t)):
	if(i >= 0):
		s += t[i]
		i -= 1
	if(j < len(t)):
		s += t[j]
		j += 1
print(s)