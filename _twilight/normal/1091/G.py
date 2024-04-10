import random
import sys

def gcd(x, y) :
    if (y == 0) : 
        return x;
    return gcd(y, x % y);

candid = [];
factor = [];

def solve(n) : 
    for d in candid :
        g = gcd(n, d);
        if (g != 1 and g != n) : 
            solve(g);
            solve(n / g);
            return
    factor.append(n);
    return

n = int(raw_input());

for i in range(35) :
    x = random.randint(1, n - 1);
    y = x * x % n;
    sys.stdout.write("sqrt " + str(y) + '\n');
    sys.stdout.flush();
    y = int(raw_input());
    if (x != y and y != -1) :
        if (x > y) : 
            x, y = y, x;
        candid.append(y - x);

solve(n)
sys.stdout.write("! " + str(len(factor)));
for x in factor :
    sys.stdout.write(" " + str(x));