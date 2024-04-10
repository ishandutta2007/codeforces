import sys
from collections import deque

sys.setrecursionlimit(501 * 501)



def is_valid(x, y):
	if (0 <= x) and (x < n) and (0 <= y) and (y < m):
		return True
	else:
		return False

def main():
	n, m = map(int, raw_input().split())
	ss = [raw_input() for i in xrange(n)]
	a = [[0 if ss[i][j] == '.' else -1 for j in xrange(m)] for i in xrange(n)]

	dirs = ((0, 1), (0, -1), (1, 0), (-1, 0))
	
	ans = []
	bans = []
	
	'''for i in xrange(n):
		str = raw_input()
		for j in xrange(m):
			if str[j] == '#':
				a[i][j] = -1
			else:
				bans.append('B {0} {1}'.format(i+1, j+1))'''
			
	q = deque()			
	qappend = q.append
	qappendleft = q.appendleft
	ansappend = ans.append
	qpop = q.pop
	
	for i in xrange(n):
		for j in xrange(m):
			if a[i][j] != -1:
				qappend((i, j))
				a[i][j] = -1
				
				while len(q):
					(x, y) = qpop()
					
					bans.append('B {0} {1}'.format(x+1, y+1))
						
					if x != i or y != j:
						ansappend('R {0} {1}'.format(x+1, y+1))
						ansappend('D {0} {1}'.format(x+1, y+1))
					
					for (dx, dy) in dirs:
						cx = x + dx
						cy = y + dy
						if (0 <= cx) and (cx < n) and (0 <= cy) and (cy < m) and a[cx][cy] != -1:
							qappendleft((cx, cy))
							a[cx][cy] = -1
	
	ans.reverse()			
	
	print(len(ans) + len(bans))
	
	print('\n'.join(bans))
	print('\n'.join(ans))
				
	
	
if __name__ == '__main__':
	main()