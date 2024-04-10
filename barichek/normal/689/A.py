s=input()
s=input()
ok=0
if ('1' not in s and '4' not in s and '7' not in s and '0' not in s):
	ok=1
if ('1' not in s and '2' not in s and '3' not in s):
	ok=1
if ('3' not in s and '6' not in s and '9' not in s and '0' not in s):
	ok=1
if ('7' not in s and '0' not in s and '9' not in s):
	ok=1
print('No' if ok==1 else 'Yes')