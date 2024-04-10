

def main():
	n, k = map(int, raw_input().split())
	
	odd_cnt = n / 2
	if (n % 2) == 1:
		odd_cnt += 1
		
	if k <= odd_cnt:
		print 2*k - 1
	else:
		print (k - odd_cnt) * 2
	
if __name__ == '__main__':
	main()