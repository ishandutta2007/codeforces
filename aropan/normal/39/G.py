
import re

import sys

import operator as op

 

fin, fout = sys.stdin, sys.stdout

 

MOD = 2 ** 15

make_op = lambda op: lambda s, o: Num(op(s.x, o.x) % MOD)

make_cmp = lambda op: lambda s, o: op(s.x, o.x)

 

class Num:

    def __init__(self, obj):

        self.x = obj.x if isinstance(obj, Num) else int(obj)

    __add__ = make_op(op.add)

    __sub__ = make_op(op.sub)

    __div__ = make_op(op.div)

    __mul__ = make_op(op.mul)

    __eq__ = make_cmp(op.eq)

    __lt__ = make_cmp(op.lt)

    __gt__ = make_cmp(op.gt)

 

def val(num):

    return num.x if isinstance(num, Num) else num

 

n = int(fin.readline())

 

text = "".join(fin.readlines())

for pat, repl in [

    (r"\s", r""),

    (r"return", "return "),

    (r".*{(.*)}.*", r"\1"),

    (r"(\d+)", r"Num(\1)"),

    (r"(if.*?)(return)", r"\1:\2"),

    (r";", "\n\t"),

    ]:

    text = re.sub(pat, repl, text)

text = "def F(n):\n\tn = Num(n)\n\t" + text

 

exec(compile(text.strip(), "f**k", 'exec'))

 

cache = {}

f = lambda n: Num(cache[val(n)])

ans = -1

for i in range(0, MOD):

    t = cache[i] = Num(F(i))

    if val(t) == n:

      ans = i

     

print(ans)