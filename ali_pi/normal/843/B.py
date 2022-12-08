from random import*
from sys import*
read=lambda :map(int,raw_input().split())
def ask(x):
	print('? {}'.format(x))
	stdout.flush()
	return tuple(read())

def answer(x):
	print('! {}'.format(x))
	stdout.flush()
	exit(0)

n,st,x=read()
a=[ask(st)]
if a[0][0]>=x: answer(a[0][0])
for i in sample(range(1,n+1),min(n,999)):
	b=ask(i)
	if b[0]<x: a.append(b)
	elif b[0]==x: answer(x)
b=max(a)
while True:
	if b[0]>=x: answer(b[0])
	if b[1]==-1: break
	else: b=ask(b[1])
answer(-1)