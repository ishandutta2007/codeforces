import sys
fa = range(26)
#def getf(x):
	#return x if fa[x] == x else fa[x]=getf(fa[x])

def transform(k):
	if fa[k]==k:
		return k
	else:
		arr=[]
		while fa[k]!=k:
			arr.append(k)
			k=fa[k]

		for el in arr:
			fa[el]=k
		return k


def main():
	n=int(raw_input())
	a=raw_input()
	b=raw_input()
	ans=0
	ll=[]
	rr=[]
	for i in range(n):
		str1i = ord(a[i]) - 97
		str2i = ord(b[i]) - 97
		str1i = transform(str1i)
		str2i = transform(str2i)
		if str1i!=str2i:
			fa[str1i]=str2i
			ans+=1
			ll.append(str1i+97)
			rr.append(str2i+97)

	print ans
	for i in range(len(ll)):
		print chr(ll[i]),chr(rr[i])

if __name__=='__main__':
	main()